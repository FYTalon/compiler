#ifndef _NODE_H_
#define _NODE_H_

#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include "symtab.h"

using namespace std;

extern FILE *Eeyore;

extern string Context;
extern vector<int>Start, End;
extern bool rn;

extern int max_index[4];
/*
0 T
1 t
2 p
3 l
*/

class Node{
public:
    virtual Symbol* generate_ir(){ return new Symbol(); }
};

class NRoot : public Node{
public:
    vector<Node*>context;
    virtual Symbol* generate_ir(){
        init();
        EnterBlock();
        string s = "getint";
        insert(&s, 0, 269, 'F');
        s = "getch";
        insert(&s, 0, 269, 'F');
        s = "getarray";
        insert(&s, 1, 269, 'F');
        s = "putint";
        insert(&s, 1, 270, 'F');
        s = "putch";
        insert(&s, 1, 270, 'F');
        s = "putint";
        insert(&s, 2, 270, 'F');
        s = "_sysy_starttime";
        insert(&s, 1, 270, 'F');
        s = "_sysy_stoptime";
        insert(&s, 1, 270, 'F');
        
        for(Node* it : context)
            it->generate_ir();
        return new Symbol();
    }
};

class NDeclare : public Node{
public:
    virtual Symbol* generate_ir(){ return new Symbol(); }
};

class NExpression : public Node{
public:
    virtual Symbol* generate_ir(){ return new Symbol(); }
};


class NStatement : public NExpression{
public:

    virtual Symbol* generate_ir(){ return new Symbol(); }
};

class NBlock : public NStatement{
public:
    vector<NStatement*> stmts;
    bool enter;
    NBlock(){
        enter = false;
    }
    virtual Symbol* generate_ir(){
        if(!enter) EnterBlock();
        for(NStatement* it : stmts)
            it->generate_ir();
        if(!enter) ExitBlock();
        return new Symbol();
    }
};

class NIdentifier : public NExpression{
public:
    string* name;
    NIdentifier(){};
    NIdentifier(string* _) : name(_) {}

    virtual Symbol* generate_ir(){
        return lookup(name);
    }
    virtual void update(){};
};

class NArrayIdentifier : public NIdentifier{
public:
    NIdentifier* name;
    vector<NExpression*> shape;
    string tmplate;
    NArrayIdentifier(NIdentifier* _name){
        name = _name; 
    }
    virtual Symbol* generate_ir(){
        Symbol* sym = lookup(name->name);
        int id = -1, id_ = -1;
        //fprintf(Eeyore, "var t%d\n", id);
        //fprintf(Eeyore, "var t%d\n", id_);
        char s[100];
        //memset(s, 0, sizeof(s));
        //sprintf(s, "t%d = 0\n", id);
        //Context += s;
        string str = *name->name + "[]";
        Symbol *index = new Symbol(0, 0, ' ');
        tmplate = "";
        for(NExpression* exp : shape){
            Symbol *sz = lookup(&str);
            Symbol *tmp = exp->generate_ir();
            
            if(tmp->type == ' ' && index->type == ' '){
                index->memloc += sz->paranum * tmp->memloc;
            }
            else {
                if(id == -1){
                    id = max_index[1]++;
                    id_ = max_index[1]++;
                    fprintf(Eeyore, "var t%d\n", id);
                    fprintf(Eeyore, "var t%d\n", id_);
                    memset(s, 0, sizeof(s));
                    sprintf(s, "t%d = %d\n", id, index->memloc);
                    Context += s;
                }
                memset(s, 0, sizeof(s));
                sprintf(s, "t%d = %d\nt%d = t%d * %c%d\nt%d = t%d + t%d\n", id_, sz->paranum, id_, id_, tmp->type, tmp->memloc, id, id, id_);
                Context += s;
            }
            str += "[]";
        }
        if(id == -1){
            memset(s, 0, sizeof(s));
            sprintf(s, "%c%d[%d]", sym->type, sym->memloc, index->memloc * 4);
            str = s;
            //printf("%s", s);
            Symbol* cst = lookup(&str);
            if(cst->type != 'Z') return cst;
            id = max_index[1]++;
            id_ = max_index[1]++;
            fprintf(Eeyore, "var t%d\n", id);
            fprintf(Eeyore, "var t%d\n", id_);
            memset(s, 0, sizeof(s));
            sprintf(s, "t%d = %d\n", id, index->memloc);
            Context += s;
        }
        memset(s, 0, sizeof(s));
        sprintf(s, "t%d = t%d * 4\nt%d = t%d\nt%d = %c%d[t%d]\n", id, id, id_, id, id, sym->type, sym->memloc, id);
        Context += s;
        memset(s, 0, sizeof(s));
        sprintf(s, "%c%d[t%d] = t%d\n", sym->type, sym->memloc, id_, id);
        tmplate = s;
        return new Symbol(0, id, 't');
    }
    virtual void update(){
        Context += tmplate;
    }
};

class NArrayInitVal : public NExpression{
public:
    vector<NArrayInitVal*> value;
    NExpression* val;
    bool end;
    NArrayInitVal(bool _end = false, NExpression* _val = NULL) : end(_end), val(_val) {}
    virtual Symbol* generate_ir(){ return new Symbol(); }
};

class NDeclareStatement : public NStatement{
public:
    vector<NDeclare*>child;
    int type;
    NDeclareStatement(int BType) : type(BType) {}
    virtual Symbol* generate_ir(){
        for(NDeclare* it : child)
            it->generate_ir();
        return new Symbol();
    }
};

class NVarDeclare : public NDeclare{
public:
    NIdentifier* name;
    NExpression* value;
    bool cst;
    NVarDeclare(NIdentifier* identation, NExpression* expression = NULL, bool flag = false) : name(identation), value(expression), cst(flag) {}
    virtual Symbol* generate_ir(){
        int id;
        if(!cst){
            insert(name->name, 0, id = max_index[0]++, 'T');
            fprintf(Eeyore, "var T%d\n", id);
            if(value != NULL){
                Symbol* tmp = value->generate_ir();
                char s[100];
                memset(s, 0, sizeof(s));
                sprintf(s, "T%d = %c%d\n", id, tmp->type, tmp->memloc);
                Context += s;
            }
            return new Symbol();
        }
        else {
            Symbol* tmp = value->generate_ir();
            insert(name->name, 0, tmp->memloc, ' ');
            return new Symbol();
        }
    }
};

class NArrayDeclare : public NDeclare{
public:
    NArrayIdentifier* name;
    NArrayInitVal* value;
    bool cst;
    NArrayDeclare(NArrayIdentifier* identation, NArrayInitVal* expression = NULL, bool flag = false) : name(identation), value(expression), cst(flag) {}
    virtual Symbol* generate_ir(){
        int id, len = 4;
        vector<int>shape;
        for(NExpression* exp : name->shape){
            int x = exp->generate_ir()->memloc;
            len*= x;
            shape.push_back(x);
        }
        for(int i = shape.size() - 2; ~i ; i--)
            shape[i] *= shape[i + 1];
        insert(name->name->name, 0, id = max_index[0]++, 'T');
        string str = *name->name->name;
        for(int i = 0; i < shape.size(); i++, str += "[]"){
            insert(&str, shape[i], id, 'T');
        }
        insert(&str, 1, id, 'T');
        fprintf(Eeyore, "var %d T%d\n", len, id);
        int pos = 0;
        if(value != NULL) initial(value, shape, id, pos, 0);
        while(cst && pos < shape[0]){
            char s[100];
            memset(s, 0, sizeof(s));
            sprintf(s, "T%d[%d] = %c%d\n", id, pos * 4, ' ', 0);
            Context += s;
            memset(s, 0, sizeof(s));
            sprintf(s, "T%d[%d]", id, pos * 4);
            string str = s;
            insert(&str, 0, 0, ' ');
            pos++;
        }
        return new Symbol();
    }

    void initial(NArrayInitVal* val, vector<int>&shape, int id, int &pos, int deep){
        if(val->end){
            if(val->val == NULL && !cst){
                pos++;
                return ;
            }
            Symbol* tmp = new Symbol(0, 0, ' ');
            if(val->val != NULL) tmp = val->val->generate_ir();
            char s[100];
            if(cst){
                memset(s, 0, sizeof(s));
                sprintf(s, "T%d[%d]", id, pos * 4);
                string str = s;
                insert(&str, 0, tmp->memloc, tmp->type);
            }
            memset(s, 0, sizeof(s));
            sprintf(s, "T%d[%d] = %c%d\n", id, pos * 4, tmp->type, tmp->memloc);
            Context += s;
            pos++;
            return ;
        }
        int plus = pos + shape[deep];
        for(NArrayInitVal* v : val->value){
            initial(v, shape, id, pos, deep + 1);
        }
        if(cst){
            while(pos < plus){
                char s[100];
                memset(s, 0, sizeof(s));
                sprintf(s, "T%d[%d] = %c%d\n", id, pos * 4, ' ', 0);
                Context += s;
                memset(s, 0, sizeof(s));
                sprintf(s, "T%d[%d]", id, pos * 4);
                string str = s;
                insert(&str, 0, 0, ' ');
                pos++;
            }
        }
        pos = plus;
    }

};

class NFunctionDefineArg : public NExpression{
public:
    virtual Symbol* generate_ir(){ return new Symbol(); }
};

class NFunctionDefineArgArray : public NFunctionDefineArg{
public:
    int type;
    NArrayIdentifier* name;
    NFunctionDefineArgArray(int _type, NArrayIdentifier* _name) : 
    type(_type), name(_name) {}
    virtual Symbol* generate_ir(){
        int id;
        vector<int>shape;
        for(NExpression* exp : name->shape){
            int x = exp->generate_ir()->memloc;
            shape.push_back(x);
        }
        for(int i = shape.size() - 2; ~i ; i--)
            shape[i] *= shape[i + 1];
        insert(name->name->name, 0, id = max_index[2]++, 'p');
        string str = *name->name->name;
        for(int i = 0; i < shape.size(); i++, str += "[]"){
            insert(&str, shape[i], id, 'p');
        }
        insert(&str, 1, id, 'p');
        return new Symbol();
    }
};

class NFunctionDefineArgVar : public NFunctionDefineArg{
public:
    int type;
    NIdentifier* name;
    NFunctionDefineArgVar(int _type, NIdentifier* _name) : 
    type(_type), name(_name) {}
    virtual Symbol* generate_ir(){
        int id;
        insert(name->name, 0, id = max_index[2]++, 'p');
        return new Symbol();
    }
};

class NFunctionDefineArgList : public NExpression {
public:
    vector<NFunctionDefineArg*> list;
    NFunctionDefineArgList() {}
    virtual Symbol* generate_ir(){
        for(NFunctionDefineArg* it : list)
            it->generate_ir();
        return new Symbol();
    }
};

class NFunctionDefine : public NDeclare{
public:
    int type;
    NIdentifier* name;
    NFunctionDefineArgList* args;
    NBlock* body;
    NFunctionDefine(int _type, NIdentifier* _name, NFunctionDefineArgList* _args, NBlock* _body) :
    type(_type), name(_name), args(_args), body(_body) {}
    virtual Symbol* generate_ir(){
        rn = false;
        insert(name->name, args->list.size(), type, 'F');
        fprintf(Eeyore, "%s", Context.c_str());
        fprintf(Eeyore, "f_%s [%d]\n", name->name->c_str(), (int)args->list.size());
        Context.clear();
        body->enter = true;
        EnterBlock();
        max_index[2] = 0;
        args->generate_ir();
        body->generate_ir();
        ExitBlock();
        fprintf(Eeyore, "%s", Context.c_str());
        if(!rn){
            fprintf(Eeyore, "return\n");
        }
        fprintf(Eeyore, "end f_%s\n", name->name->c_str());
        Context.clear();
        return new Symbol();
    }
};

class NArgList :  public NExpression{
public:
    vector<NExpression*> list;
    virtual Symbol* generate_ir(){
        for(NExpression* it : list){
            Symbol* tmp = it->generate_ir();
            char s[100];
            memset(s, 0, sizeof(s));
            sprintf(s, "param %c%d\n", tmp->type, tmp->memloc);
            Context += s;
        }
        return new Symbol();
    }
};

class NFunctionCall : public NExpression{
public:
    NIdentifier* name;
    NArgList* args;
    NFunctionCall(NIdentifier* _, NArgList* __) : name(_), args(__) {}
    virtual Symbol* generate_ir(){
        args->generate_ir();
        char s[100];
        memset(s, 0, sizeof(s));
        Symbol* tmp = lookup(name->name);
        if(tmp->memloc == 269){
            int id = max_index[1]++;
            fprintf(Eeyore, "var t%d\n", id);
            sprintf(s, "t%d = call f_%s\n", id, name->name->c_str());
            Context += s;
            return new Symbol(0, id, 't');
        }
        sprintf(s, "call f_%s\n", name->name->c_str());
        Context += s;
        return new Symbol();
    }
};

class NAssignment : public NStatement {
public:
    NIdentifier* l;
    NExpression* r;
    NAssignment(NIdentifier* _l, NExpression* _r) : l(_l), r(_r) {}
    virtual Symbol* generate_ir(){
        Symbol* tmp = l->generate_ir();
        Symbol* rhs = r->generate_ir();
        char s[100];
        memset(s, 0, sizeof(s));
        sprintf(s, "%c%d = %c%d\n", tmp->type, tmp->memloc, rhs->type, rhs->memloc);
        Context += s;
        l->update();
        return tmp;
    }
};

class NEval : public NStatement{
public:
    NExpression* exp;
    NEval(NExpression* _e) : exp(_e) {}
    virtual Symbol* generate_ir(){
        return exp->generate_ir();
    }
};

class NVoid : public NStatement{
public:
    virtual Symbol* generate_ir(){
        return new Symbol();
    }
};


class NConditionExpression : public NExpression {
public:
    NExpression* val;
    NConditionExpression(NExpression* _) : val(_) {}
    virtual Symbol* generate_ir(){
        return val->generate_ir();
    }
};

class NIfElse : public NStatement{
public:
    NConditionExpression* cond;
    NStatement* ifstmt;
    NStatement* elsestmt;
    NIfElse(NConditionExpression* _, NStatement* __, NStatement* ___) :
        cond(_), ifstmt(__), elsestmt(___) {}
    virtual Symbol* generate_ir(){
        Symbol* tmp = cond->generate_ir();
        char s[100];
        memset(s, 0, sizeof(s));
        int id = max_index[3]++;
        sprintf(s, "if %c%d == 0 goto l%d\n", tmp->type, tmp->memloc, id);
        Context += s;
        ifstmt->generate_ir();
        memset(s, 0, sizeof(s));
        int end = max_index[3]++;
        sprintf(s, "goto l%d\nl%d:\n", end, id);
        Context += s;
        elsestmt->generate_ir();
        memset(s, 0, sizeof(s));
        sprintf(s, "l%d:\n", end);
        Context += s;
        return new Symbol();
    }
};

class NWhile : public NStatement{
public:
    NConditionExpression* cond;
    NStatement* stmt;
    NWhile(NConditionExpression* _, NStatement* __) : cond(_), stmt(__) {}
    virtual Symbol* generate_ir(){
        int bg = max_index[3]++;
        char s[100];
        memset(s, 0, sizeof(s));
        sprintf(s, "l%d:\n", bg);
        Context += s;
        Symbol* tmp = cond->generate_ir();
        int end = max_index[3]++;
        memset(s, 0, sizeof(s));
        sprintf(s, "if %c%d == 0 goto l%d\n", tmp->type, tmp->memloc, end);
        Context += s;
        Start.push_back(bg);
        End.push_back(end);
        stmt->generate_ir();
        memset(s, 0, sizeof(s));
        sprintf(s, "goto l%d\nl%d:\n", bg, end);
        Context += s;
        Start.pop_back();
        End.pop_back();
        return new Symbol();
    }
};

class NBreak : public NStatement {
public:
    virtual Symbol* generate_ir(){
        char s[100];
        memset(s, 0, sizeof(s));
        sprintf(s, "goto l%d\n", End[End.size() - 1]);
        Context += s;
        return new Symbol();
    }
};

class NContinue : public NStatement {
public:
    virtual Symbol* generate_ir(){
        char s[100];
        memset(s, 0, sizeof(s));
        sprintf(s, "goto l%d\n", Start[Start.size() - 1]);
        Context += s;
        return new Symbol();
    }
};

class NReturn : public NStatement {
public:
    NExpression* val;
    NReturn(NExpression* _ = NULL) : val(_) {}
    virtual Symbol* generate_ir(){
        char s[100];
        memset(s, 0, sizeof(s));
        if(val != NULL){
            Symbol* tmp = val->generate_ir();
            sprintf(s, "return %c%d\n", tmp->type, tmp->memloc);
        }
        else 
            sprintf(s, "return\n");
        rn = true;
        Context += s;
        return new Symbol();
    }
};

class NNumber : public NExpression{
public:
    int val;
    NNumber(const string& v){
        val = 0;
        if(v[0] == '0'){
            if(v[1] == 'x' || v[1] == 'X'){
                for(int i = 2; i < v.length(); i++)
                    if(v[i] >= '0' && v[i] <= '9')
                        val = val * 16 + v[i] - '0';
                    else if(v[i] >= 'a' && v[i] <= 'z')
                        val = val * 16 + 10 + v[i] - 'a';
                    else 
                        val = val * 16 + 10 + v[i] - 'A';
            }
            else {
                for(int i = 1; i < v.length(); i++)
                    val = val * 8 + v[i] - '0';
            }
        }
        else {
            for(int i = 0; i < v.length(); i++)
                val = val * 10 + v[i] - '0';
        }
    }
    NNumber(){
        val = -1;
    }
    virtual Symbol* generate_ir(){
        return new Symbol(0, val, ' ');
    }
};

class NUnaryExpression : public NExpression{
public:
    int op;
    NExpression* val;
    NUnaryExpression(int _, NExpression* __){
        op = _;
        val = __;
    }
    virtual Symbol* generate_ir();
};

class NBinaryExpression : public NExpression{
public:
    int op;
    NExpression* l;
    NExpression* r;
    NBinaryExpression(NExpression* _, int __, NExpression* ___) : l(_), op(__), r(___) {}
    virtual Symbol* generate_ir();
};


#endif
