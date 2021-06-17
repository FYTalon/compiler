#ifndef _TNODE_H_
#define _TNODE_H_

#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include "tymbol.h"

using namespace std;

extern FILE *Tigger;
extern bool inFunc;
extern string inits;
extern int pnum;

class TNode{
public:
    virtual void generate_ir(){}
};

class TRoot : public TNode{
public:
    vector<TNode*>context;
    virtual void generate_ir(){
        Einit();
        for(auto i : context){
            i->generate_ir();
        }
            
    }
};

extern TRoot* Troot;

class TStatement : public TNode{
public:
    virtual void generate_ir(){}
};

class TVar : public TNode{
public:
    int index;
    char type;
    TVar(char _, int __) : index(__), type(_) {}
    virtual void generate_ir(){}
    string *get_name(){
        string *str = new string();
        *str = type + to_string(index);
        return str;
    }
};

class TValue : public TNode{
public:
    TVar* v;
    int val;
    TValue (TVar* var = NULL, string* value = NULL){
        v = var;
        if(value != NULL) val = atoi(value->c_str());
        else val = 0;
    }
    virtual void generate_ir(){}
    string opt(){
        if(v != NULL) return get_var_reg(v->get_name());
        else return to_string(val);
    }
    string obt(){
        if(v != NULL) return get_var_reg(v->get_name());
        else {
            TContext += "t0 = " + to_string(val) + "\n";
            return "t0";
        }
    }
};


class TDeclare : public TStatement{
public:
    TVar *v;
    int length;
    TDeclare(string *str, TVar* var){
        if(str != NULL) length = atoi(str->c_str());
        else length = -1;
        v = var;
    }
    virtual void generate_ir(){
        if(length != -1){
            insert(v->get_name(), length, true);
            if(!inblock) fprintf(Tigger, "%s\n", (get_var(v->get_name()) + " = malloc " + to_string(length)).c_str()) ;
        }
        else {
            insert(v->get_name(), 4, false);
            if(!inblock) fprintf(Tigger, "%s\n", (get_var(v->get_name()) + " = 0").c_str());
        }
    }
};

class TInitialize : public TNode{
public:
    TVar *v;
    int length;
    int val;
    TInitialize(TVar *var, string *p, string *w){
        v = var;
        if(p == NULL) length = -1;
        else length = atoi(p->c_str());
        val = atoi(w->c_str());
    }
    virtual void generate_ir(){
        if(!val) return ;
        clear();
        string reg = length != -1 ? get_arr_reg(v->get_name(), length) : get_var_reg(v->get_name());
        inits += TContext;
        TContext.clear();
        inits += reg + " = " + to_string(val) + "\n";
        save();
        inits += TContext;
        TContext.clear();
    }
};

class TBlock : public TNode{
public:
    vector<TStatement*>list;
    virtual void generate_ir(){
        clear();
        for(auto i : list)
            i->generate_ir();
        save();
    }
};

class TFunctionDef : public TNode{
public:
    string *ident;
    int p;
    TBlock* body;
    TFunctionDef(string *str, string *num, TBlock *b){
        ident = str;
        p = atoi(num->c_str());
        body = b;
    }
    virtual void generate_ir(){
        TContext.clear();
        enter_block(p);
        body->generate_ir();
        fprintf(Tigger, "%s [%d] [%d]\n", ident->c_str(), p, get_max());
        if(*ident == "f_main") fprintf(Tigger, "%s", inits.c_str());
        fprintf(Tigger, "%s", TContext.c_str());
        fprintf(Tigger, "end %s\n", ident->c_str());
        exit_block();
    }
};

class TExpression : public TStatement{
public:
    TVar *v;
    TValue *Rval;
    TExpression(TVar* var = NULL, TValue* Rv = NULL) : v(var), Rval(Rv){}
    virtual void generate_ir(){
        
        string reg = get_var_reg(v->get_name());
        ban[reg] = true;
        string r = Rval->opt();
        TContext += reg + " = " + r + "\n";
        ban.clear();
        //save();
    }
};

class TBinaryExpression : public TExpression{
public:
    TValue *lval, *rval;
    string *op;
    TBinaryExpression(TVar* var, TValue* lv, string *Op, TValue* rv) : TExpression(var){
        op = Op;
        lval = lv;
        rval = rv;
    }
    virtual void generate_ir(){
        string reg = get_var_reg(v->get_name());
        ban[reg] = true;
        string l = lval->obt();
        ban[l] = true;
        string r = rval->opt();
        TContext += reg + " = " + l + " " + (*op) + " " + r + "\n";
        ban.clear();
        //save();
    }
};

class TUnaryExpression : public TExpression{
public:
    string *op;
    TUnaryExpression(TVar* var, string* Op, TValue* rv) : TExpression(var, rv){
        op = Op;
    }
    virtual void generate_ir(){
        string reg = get_var_reg(v->get_name());
        ban[reg] = true;
        string r = Rval->obt();
        TContext += reg + " = " + (*op) + r + "\n";
        ban.clear();
        //save();
    }
};

class TV2AExpression : public TExpression{
public:
    TValue *num;
    TV2AExpression(TVar* var, TValue* num_, TValue* rv) : TExpression(var, rv){
        num = num_;
    }
    virtual void generate_ir(){
        string reg;
        if(num->v != NULL)
            reg = get_arr_reg(v->get_name(), num->v->get_name());
        else reg = get_arr_reg(v->get_name(), num->val);
        ban[reg] = true;
        TContext += reg + "[0] = " + Rval->obt() + "\n";
        ban.clear();
        //save();
    }
};

class TA2VExpression : public TExpression{
public:
    TVar* rhs;
    TValue *num;
    TA2VExpression(TVar* var, TValue* num_, TVar* rv) : TExpression(var){
        num = num_;
        rhs = rv;
    }
    virtual void generate_ir(){
        string reg;
        
        if(num->v != NULL){
            reg = get_arr_reg(rhs->get_name(), num->v->get_name());
            //printf("%s\n", num->v->get_name()->c_str());
        }
            
        else reg = get_arr_reg(rhs->get_name(), num->val);
        
        ban[reg] = true;
        TContext += get_var_reg(v->get_name()) + " = " + reg + "[0]\n";
        ban.clear();
        //save();
    }
};

class TIfExpression : public TExpression{
public:
    TValue *lv, *rv;
    string *op;
    TVar *l;
    TIfExpression(TValue* l = NULL, string* Op = NULL, TValue* r = NULL, TVar* label = NULL) :
        lv(l), rv(r), op(Op), l(label) {}
    virtual void generate_ir(){
        save();
        if(op != NULL){
            string str = lv->obt();
            ban[str] = true;
            TContext += (string)"if " + str + " " + (*op) + " " + rv->obt() + " ";
        
        }
        TContext += (string)"goto " + (*l->get_name()) + "\n";
        ban.clear();
        clear();
    }
};

class TLabel : public TExpression{
public:
    TVar *l;
    TLabel(TVar* label) : l(label) {}
    virtual void generate_ir(){
        save();
        TContext += (*l->get_name()) + ":\n";
        clear();
    }
};

class TParam : public TExpression{
public:
    TValue* val;
    TParam(TValue* v) : val(v) {}
    virtual void generate_ir(){
        int id = pnum++;
        TContext += "a" + to_string(id) + " = " + val->obt() + "\n";
    }
};

class TFunctionCall : public TExpression{
public:
    string *ident;
    TFunctionCall(TVar* var = NULL, string* str = NULL) : TExpression(var), ident(str) {}
    virtual void generate_ir(){
        save();
        TContext += (string)"call " + (*ident) + "\n";
        clear();
        if(v != NULL){
            string reg = get_var_reg(v->get_name());
            TContext += reg + " = a0\n";
        }
        pnum = 0;
    }
};

class TReturn : public TExpression{
public:
    TValue* val;
    TReturn(TValue* v = NULL) : val(v) {}
    virtual void generate_ir(){
        save();
        if(val != NULL){
            TContext += (string)"a0 = " + val->opt() + "\n";
        }
        TContext += "return\n";
        clear();
    }
};

#endif