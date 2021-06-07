%define api.prefix {zz}
%{
#include "Tnode.h"
#include <cstdio>
#include <cstdlib>
#include "Eeyore2Tigger.tab.hpp"
using namespace std;

extern int zzdebug;
extern int zzlex();
extern int zzget_lineno();
extern int zzlex_destroy();
void zzerror(const char *s){ printf("Error:%s\natline: %d: \n", s, zzget_lineno()); zzlex_destroy(); exit(1); }
%}

%union {
    int token;
    string *str;

    TRoot* root;
    TVar* var;
    TDeclare* decl;
    TInitialize* init;
    TFunctionDef* funcdef;
    TBlock* block;
    TStatement* stmt;
    TExpression* expr;
    TValue* value;
}

%token <str> EFUNCIDENT EINTEGER;
%token <var> EVAR ELABEL
%token <token> EEND ECALL EPARAM EIF EGOTO ERETURN EVARDEF
%token <str> EASSIGN EEQ ENQ ELT ELQ EGT EGQ EAND EOR ENOT EPLUS EMINUS EMUL EDIV EMOD
%token <token> ELPAREN ERPAREN ELSQUARE ERSQUARE ELBRACE ERBRACE ECOLON

%type <root> Program

%type <decl> Declaration
%type <init> Initialization
%type <block> Statements
%type <stmt> Statement
%type <funcdef> FunctionDef
%type <expr> Expression
%type <value> RVal
%type <str> UnaryOp BinaryOp LogicOp

%%
Program: Program Declaration {
           $$->context.push_back($2);
       }
       | Program Initialization {
           $$->context.push_back($2);
       }
       | Program FunctionDef {
           $$->context.push_back($2);
       }
       | { $$ = new TRoot(); Troot = $$; }
       ;

Declaration: EVARDEF EINTEGER EVAR {
                $$ = new TDeclare($2, $3);
           }
           | EVARDEF EVAR {
                $$ = new TDeclare(NULL, $2);
           }
           ;

Initialization: EVAR EASSIGN EINTEGER {
                   $$ = new TInitialize($1, NULL, $3);
              }
              | EVAR ELSQUARE EINTEGER ERSQUARE EASSIGN EINTEGER {
                   $$ = new TInitialize($1, $3, $6);
              }
              ;

FunctionDef: EFUNCIDENT ELSQUARE EINTEGER ERSQUARE Statements EEND EFUNCIDENT {
                $$ = new TFunctionDef($1, $3, $5);
           }
           ;

Statements: Statements Statement {
                $$->list.push_back($2);
          }
          | {
                $$ = new TBlock();
          }
          ;

Statement: Expression { $$ = $1; }
        | Declaration { $$ = $1; }
        ;

Expression: EVAR EASSIGN RVal BinaryOp RVal {
              $$ = new TBinaryExpression($1, $3, $4, $5);
          }
          | EVAR EASSIGN UnaryOp RVal {
              $$ = new TUnaryExpression($1, $3, $4);
          }
          | EVAR EASSIGN RVal {
              $$ = new TExpression($1, $3);
          }
          | EVAR ELSQUARE RVal ERSQUARE EASSIGN RVal {
              $$ = new TV2AExpression($1, $3, $6);
          }
          | EVAR EASSIGN EVAR ELSQUARE RVal ERSQUARE {
              $$ = new TA2VExpression($1, $5, $3);
          }
          | EIF RVal LogicOp RVal EGOTO ELABEL {
              $$ = new TIfExpression($2, $3, $4, $6);
          }
          | EGOTO ELABEL {
              $$ = new TIfExpression(NULL, NULL, NULL, $2);
          }
          | ELABEL ECOLON {
              $$ = new TLabel($1);
          }
          | EPARAM RVal {
              $$ = new TParam($2);
          }
          | ECALL EFUNCIDENT {
              $$ = new TFunctionCall(NULL, $2);
          }
          | EVAR EASSIGN ECALL EFUNCIDENT {
              $$ = new TFunctionCall($1, $4);
          }
          | ERETURN RVal {
              $$ = new TReturn($2);
          }
          | ERETURN {
              $$ = new TReturn();
          }
          ;

RVal: EVAR { $$ = new TValue($1); }
    | EINTEGER { $$ = new TValue(NULL, $1); }
    ;

BinaryOp: UnaryOp
        | LogicOp
        ;

UnaryOp: EMINUS
       | ENOT
       ;

LogicOp: EEQ
       | ENQ
       | ELT
       | ELQ
       | EGT
       | EGQ
       | EAND
       | EOR
       | EPLUS
       | EMINUS
       | EMUL
       | EDIV
       | EMOD
       ;



%%