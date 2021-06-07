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

%token <str> FUNCIDENT INTEGER;
%token <var> VAR LABEL
%token <token> END CALL PARAM IF GOTO RETURN VARDEF
%token <str> ASSIGN EQ NQ LT LQ GT GQ AND OR NOT PLUS MINUS MUL DIV MOD
%token <token> LPAREN RPAREN LSQUARE RSQUARE LBRACE RBRACE COLON

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
       | { $$ = new TRoot(); root = $$; }
       ;

Declaration: VARDEF INTEGER VAR {
                $$ = new TDeclare($2, $3);
           }
           | VARDEF VAR {
                $$ = new TDeclare(NULL, $2);
           }
           ;

Initialization: VAR ASSIGN INTEGER {
                   $$ = new TInitialize($1, NULL, $3);
              }
              | VAR LSQUARE INTEGER RSQUARE ASSIGN INTEGER {
                   $$ = new TInitialize($1, $3, $6);
              }
              ;

FunctionDef: FUNCIDENT LSQUARE INTEGER RSQUARE Statements END FUNCIDENT {
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

Expression: VAR ASSIGN RVal BinaryOp RVal {
              $$ = new TBinaryExpression($1, $3, $4, $5);
          }
          | VAR ASSIGN UnaryOp RVal {
              $$ = new TUnaryExpression($1, $3, $4);
          }
          | VAR ASSIGN RVal {
              $$ = new TExpression($1, $3);
          }
          | VAR LSQUARE RVal RSQUARE ASSIGN RVal {
              $$ = new TV2AExpression($1, $3, $6);
          }
          | VAR ASSIGN VAR LSQUARE RVal RSQUARE {
              $$ = new TA2VExpression($1, $5, $3);
          }
          | IF RVal LogicOp RVal GOTO LABEL {
              $$ = new TIfExpression($2, $3, $4, $6);
          }
          | GOTO LABEL {
              $$ = new TIfExpression(NULL, NULL, NULL, $2);
          }
          | LABEL COLON {
              $$ = new TLabel($1);
          }
          | PARAM RVal {
              $$ = new TParam($2);
          }
          | CALL FUNCIDENT {
              $$ = new TFunctionCall(NULL, $2);
          }
          | VAR ASSIGN CALL FUNCIDENT {
              $$ = new TFunctionCall($1, $4);
          }
          | RETURN RVal {
              $$ = new TReturn($2);
          }
          | RETURN {
              $$ = new TReturn();
          }
          ;

RVal: VAR { $$ = new TValue($1); }
    | INTEGER { $$ = new TValue(NULL, $1); }
    ;

BinaryOp: UnaryOp
        | LogicOp
        ;

UnaryOp: MINUS
       | NOT
       ;

LogicOp: EQ
       | NQ
       | LT
       | LQ
       | GT
       | GQ
       | AND
       | OR
       | PLUS
       | MINUS
       | MUL
       | DIV
       | MOD
       ;



%%