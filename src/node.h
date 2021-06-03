#ifndef _NODE_H_
#define _NODE_H_

#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include "symtab.h"
#include "y.tab.h"

using namespace std;

extern FILE *Eeyore;

string Declare, Context;
vector<int>Start, End;

int max_index[4];
/*
0 T
1 t
2 p
*/

class Node{
public:
    virtual ~Node();
    virtual Symbol* generate_ir();
};

class NRoot : public Node{
public:
    vector<Node*>context;
    virtual Symbol* generate_ir(){
        init();
        EnterBlock();
        for(Node* it : context)
            it->generate_ir();
        return new Symbol();
    }
};

class NDeclare : public Node{
public:

};

class NIdentifier : public Node{
public:
    string* name;
    NIdentifier(string* _) : name(_) {}
};

class NArrayIdentifier : public NIdentifier{
public:
    NIdentifier* name;
    vector<NExpression*> shape;
    NArrayIdentifier(NIdentifier* _name) : name(_name) {}
};

class NArrayInitVal : public NExpression{
public:
    vector<NArrayInitVal*> value;
    NExpression* val;
    bool end;
    NArrayInitVal(bool _end = false, NExpression* _val = NULL) : end(_end), val(_val) {}
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
    NVarDeclare(NIdentifier* identation) : name(identation) { value = NULL; }
    NVarDeclare(NIdentifier* identation, NExpression* expression) : name(identation), value(expression) {}
    virtual Symbol* generate_ir(){
        int id;
        insert(name->name, 0, id = max_index[0]++, 'T');
        fprintf(Eeyore, "var T%d\n", id);
        if(value != NULL){
            Symbol* tmp = value.generate_ir();
            char s[100];
            memset(s, 0, sizeof(s));
            sprintf(s, "T%d = %c%d\n", id, tmp->type, tmp->memloc);
            Context += s;
        }
        return new Symbol();
    }
};

class NArrayDeclare : public NDeclare{
public:
    NArrayIdentifier* name;
    NArrayInitVal* value;
    NArrayDeclare(NArrayIdentifier* identation) : name(identation) { value = NULL;}
    NArrayDeclare(NArrayIdentifier* identation, NArrayInitVal* expression) : name(identation), value(expression) {}
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
        fprintf(Eeyore, "var %d T%d\n", len, id);
        int pos = 0;
        initial(value, shape, id, pos, 0);
    }

    void initial(NArrayInitVal* val, vector<int>&shape, int id, int &pos, int deep){
        if(val->end){
            Symbol* tmp = val->val->generate_ir();
            char s[100];
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
        pos = plus;
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
        insert(name->name, args.size(), type, 'F');
        fprintf(Eeyore, "f_%s [%d]\n", name->name->c_str(), args.size());
        Context.clear();
        body->enter = true;
        EnterBlock();
        max_index[2] = 0;
        args->generate_ir();
        body->generate_ir();
        ExitBlock();
        fprintf(Eeyore, "%s\n", Context.c_str());
        fprintf(Eeyore, "end f_%s\n", name->name->c_str());
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

class NFunctionDefineArg : public NExpression{
public:
    int type;
    NIdentifier* name;
    NFunctionDefineArg(int _type, NIdentifier* _name) : 
    type(_type), name(_name) {}
    virtual Symbol* generate_ir(){
        int id;
        insert(name->name, 0, id = max_index[2]++, 'p');
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
        if(tmp->memloc == INT){
            int id = max_index[1]++;
            sprintf(s, "t%d = call f_%s\n", id, name->name->c_str());
        }
        else sprintf(s, "call f_%s\n", name->name->c_str());
        Context += s;
    }
};

class NStatement : public NExpression{
public:

};

class NBlock : public NStatement{
public:
    vector<NStatement*> stmts;
    bool enter;
    NBlock(){
        enter = false;
    }
    virtual Symbol* tmp(){
        if(!enter) EnterBlock();
        for(NStatement* it : stmts)
            it->generate_ir();
        if(!enter) ExitBlock();
        return new Symbol();
    }
};

class NAssignment : public NStatement {
public:
    NIdentifier* l;
    NExpression* r;
    NAssignment(NIdentifier* _l, NExpression* _r) : l(_l), r(_r) {}
    virtual Symbol* generate_ir(){
        Symbol* tmp = lookup(l->name);
        Symbol* rhs = r->generate_ir();
        char s[100];
        memset(s, 0, sizeof(s));
        sprintf(s, "%c%d = %c%d\n", tmp->type, tmp->memloc, rhs->type, rhs->memloc);
        Context += s;
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
        memest(s, 0, sizeof(s));
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
        sprintf("l%d:\n", bg);
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
        sprintf("l%d:\n", end);
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
    NReturnStatement(NExpression* _ = NULL) : val(_) {}
    virtual Symbol* generate_ir(){
        char s[100];
        memset(s, 0, sizeof(s));
        if(val != NULL){
            Symbol* tmp = val->generate_ir();
            sprintf(s, "return %c%d\n", tmp->type, tmp->memloc);
        }
        else 
            sprintf(s, "return\n");
        Context += s;
        return new Symbol();
    }
};

class NExpression : public Node{
public:
};

class NNumber : public NExpression{
    int val;
    NNumber(const string& v, int type){
        val = 0;
        switch(type){
            case OINTEGER:
                for(int i = 1; i < v.length(); i++)
                    val = val * 8 + v[i] - '0';
                break;
            case DINTEGER:
                for(int i = 0; i < v.length(); i++)
                    val = val * 10 + v[i] - '0';
                break;
            case HINTEGER:
                for(int i = 2; i < v.length(); i++)
                    if(v[i] >= '0' && v[i] <= '9')
                        val = val * 16 + v[i] - '0';
                    else if(v[i] >= 'a' && v[i] <= 'z')
                        val = val * 16 + 10 + v[i] - 'a';
                    else 
                        val = val * 16 + 10 + v[i] - 'A';
        }
        return new Symbol(0, val, ' ');
    }
};

class NUnaryExpression : public NExpression{
public:
    int op;
    NExpression* val;
    NUnaryExpression(int _, NUnaryExpression* __) : op(_), val(__) {}
    virtual Symbol* generate_ir(){
        Symbol* tmp = val->generate_ir();
        if(tmp->type == ' '){
            switch(op){
                case PLUS:
                    return tmp;
                case MINUS:
                    tmp->memloc = -tmp->memloc;
                    return tmp;
                case NOT:
                    tmp->memloc = !tmp->memloc;
                    return tmp;
            }
        }
        else {
            int id = max_index[1]++;
            fprintf(Eeyore, "var t%d\n", id);
            char s[100];
            memset(s, 0, sizeof(s));
            Symbol* rt = new Symbol(tmp->paranum, tmp->type, tmp->memloc);
            switch(op){
                case PLUS:
                    sprintf(s, "t%d = %c%d\n", id, tmp->type, tmp->memloc);
                    break;
                case MINUS:
                    sprintf(s, "t%d = -%c%d\n", id, tmp->type, tmp->memloc);
                    rt->memloc = -rt->memloc;
                    break;
                case NOT:
                    sprintf(s, "t%d = !%c%d\n", id, tmp->type, tmp->memloc);
                    rt->memloc = !rt->memloc;
            }
            Context += s;
            return rt;
        }
    }
}

class NBinaryExpression : public NExpression{
    int op;
    NExpression* l;
    NExpression* r;
    NBinaryExpression(NExpression* _, int __, NExpression* ___) : l(_), op(__), r(___) {}
    virtual Symbol* generate_ir(){
        Symbol* lhs = l->generate_ir();
        Symbol* rhs = r->generate_ir();
        if(lhs->type == rhs->type && lhs->type == ' '){
            switch(op){
                case MUL:
                    return new Symbol(0, lhs->memloc * rhs->memloc, ' ');
                case DIV:
                    return new Symbol(0, lhs->memloc / rhs->memloc, ' ');
                case MOD:
                    return new Symbol(0, lhs->memloc % rhs->memloc, ' ');
                case PLUS:
                    return new Symbol(0, lhs->memloc + rhs->memloc, ' ');
                case MINUS:
                    return new Symbol(0, lhs->memloc - rhs->memloc, ' ');
                case LT:
                    return new Symbol(0, lhs->memloc < rhs->memloc, ' ');
                case LQ:
                    return new Symbol(0, lhs->memloc <= rhs->memloc, ' ');
                case GT:
                    return new Symbol(0, lhs->memloc > rhs->memloc, ' ');
                case GQ:
                    return new Symbol(0, lhs->memloc >= rhs->memloc, ' ');
                case EQ:
                    return new Symbol(0, lhs->memloc == rhs->memloc, ' ');
                case NQ:
                    return new Symbol(0, lhs->memloc != rhs->memloc, ' ');
                case AND:
                    return new Symbol(0, lhs->memloc && rhs->memloc, ' ');
                case OR:
                    return new Symbol(0, lhs->memloc || rhs->memloc, ' ');
            }
        }
        else {
            int id = max_index[1]++;
            char s[100];
            memset(s, 0, sizeof(s));
            fprintf(Eeyore, "var t%d\n", id);
            switch(op){
                case MUL:
                    sprintf(s, "t%d = %c%d * %c%d\n", id, lhs->type, lhs->memloc, rhs->type, rhs->memloc);
                    break;
                case DIV:
                    sprintf(s, "t%d = %c%d / %c%d\n", id, lhs->type, lhs->memloc, rhs->type, rhs->memloc);
                    break;
                case MOD:
                    sprintf(s, "t%d = %c%d % %c%d\n", id, lhs->type, lhs->memloc, rhs->type, rhs->memloc);
                    break;
                case PLUS:
                    sprintf(s, "t%d = %c%d + %c%d\n", id, lhs->type, lhs->memloc, rhs->type, rhs->memloc);
                    break;
                case MINUS:
                    sprintf(s, "t%d = %c%d - %c%d\n", id, lhs->type, lhs->memloc, rhs->type, rhs->memloc);
                    break;
                case LT:
                    sprintf(s, "t%d = %c%d < %c%d\n", id, lhs->type, lhs->memloc, rhs->type, rhs->memloc);
                    break;
                case LQ:
                    sprintf(s, "t%d = %c%d <= %c%d\n", id, lhs->type, lhs->memloc, rhs->type, rhs->memloc);
                    break;
                case GT:
                    sprintf(s, "t%d = %c%d > %c%d\n", id, lhs->type, lhs->memloc, rhs->type, rhs->memloc);
                    break;
                case GQ:
                    sprintf(s, "t%d = %c%d >= %c%d\n", id, lhs->type, lhs->memloc, rhs->type, rhs->memloc);
                    break;
                case EQ:
                    sprintf(s, "t%d = %c%d == %c%d\n", id, lhs->type, lhs->memloc, rhs->type, rhs->memloc);
                    break;
                case NQ:
                    sprintf(s, "t%d = %c%d != %c%d\n", id, lhs->type, lhs->memloc, rhs->type, rhs->memloc);
                    break;
                case AND:
                    sprintf(s, "t%d = %c%d && %c%d\n", id, lhs->type, lhs->memloc, rhs->type, rhs->memloc);
                    break;
                case OR:
                    sprintf(s, "t%d = %c%d || %c%d\n", id, lhs->type, lhs->memloc, rhs->type, rhs->memloc);
                    break;
            }
            Context += s;
            return new Symbol(0, id, 't');
        }
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



#endif
