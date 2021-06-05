#include "node.h"
#include "parser.tab.hpp"

FILE *Eeyore;
string Context;
vector<int>Start, End;

int max_index[4];

Symbol* NBinaryExpression::generate_ir(){
        char s[100];
        if(op == AND){
            Symbol* lhs = l->generate_ir();
            if(lhs->type == ' '){
                if(lhs->memloc != 0) return r->generate_ir();
                else return new Symbol(0, 0, ' ');
            }
            memset(s, 0, sizeof(s));
            int l1 = max_index[3]++, l2 = max_index[3]++, id = max_index[1]++;
            sprintf(s, "if %c%d == 0 goto l%d\n", lhs->type, lhs->memloc, l1);
            Context += s;
            Symbol* rhs = r->generate_ir();
            memset(s, 0, sizeof(s));
            fprintf(Eeyore, "var t%d\n", id);
            sprintf(s, "t%d = %c%d\ngoto l%d:\nl%d:\nt%d = 0\nl%d:\n", id, rhs->type, rhs->memloc, l2, l1, id, l2);
            Context += s;
            return new Symbol(0, id, 't');
        }
        else if(op == OR){
            Symbol* lhs = l->generate_ir();
            if(lhs->type == ' '){
                if(lhs->memloc == 0) return r->generate_ir();
                else return new Symbol(0, 1, ' ');
            }
            int l1 = max_index[3]++, l2 = max_index[3]++, id = max_index[1]++;
            sprintf(s, "if %c%d != 0 goto l%d\n", lhs->type, lhs->memloc, l1);
            Context += s;
            memset(s, 0, sizeof(s));
            Symbol* rhs = r->generate_ir();
            fprintf(Eeyore, "var t%d\n", id);
            sprintf(s, "t%d = %c%d\ngoto l%d:\nl%d:\nt%d = 1\nl%d:\n", id, rhs->type, rhs->memloc, l2, l1, id, l2);
            Context += s;
            memset(s, 0, sizeof(s));
            return new Symbol(0, id, 't');
        }

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
            }
        }
        else {
            int id = max_index[1]++;
            
            fprintf(Eeyore, "var t%d\n", id);
            switch(op){
                case MUL:
                    sprintf(s, "t%d = %c%d * %c%d\n", id, lhs->type, lhs->memloc, rhs->type, rhs->memloc);
                    break;
                case DIV:
                    sprintf(s, "t%d = %c%d / %c%d\n", id, lhs->type, lhs->memloc, rhs->type, rhs->memloc);
                    break;
                case MOD:
                    sprintf(s, "t%d = %c%d %% %c%d\n", id, lhs->type, lhs->memloc, rhs->type, rhs->memloc);
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
            }
            Context += s;
            return new Symbol(0, id, 't');
        }
}

Symbol* NUnaryExpression::generate_ir(){
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