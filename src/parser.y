%{
#include "node.h"
#include <cstdio>
#include <cstdlib>
using namespace std;

extern int yydebug;

extern int yylex();
extern int yyget_lineno();
extern int yylex_destroy();
void yyerror(const char *s) { printf("Error:%s\nat line: %d: \n", s, yyget_lineno()); yylex_destroy(); if (!yydebug) exit(1); }

static NRoot* root;
%}

%union {
    int token;
    NIdentifier* ident;
    NRoot* root;
    NDeclare_statement* declare_statement;
    NDeclare* declare;
    NExpression* expr;
    NArrayInitVal* array_init_val;
    NArrayIdentifier* array_identifier;
    NFunctionDefine* fundef;
    NFunctionDefineArgList* fundefarglist;
    NFunctionDefineArg* fundefarg;
    NArgList* arglist;
    NBlock* block;
    NStatement* stmt;

    NCondition* cond;
}

%type <string> INTEGER IDENTIFIER
%type <token> IF ELSE WHILE BREAK CONTINUE RETURN 
%type <token> CONST INT VOID
%type <token> FuncType
%type <token> ASSIGN EQ NQ LT LQ GT GQ AND OR NOT PLUS MINUS MUL DIV MOD
%type <token> LPAREN RPAREN LSQUARE RSQUARE LBRACE RBRACE COMMA SEMI

%type <root> CompUnit

%type <declare_statement> Decl ConstDecl VarDecl
%type <declare> ConstDef ConstDefSingle ConstDefArray Def DefSingle DefArray

%type <token> BType
%type <ident> IDENT LVal

%type <array_identifier> DefArrayName ArrayItem
%type <array_init_val> InitValArray InitValArrayInner

%type <token> UnaryOp MulOp AddOp RelOp EqOp
%type <expr> InitVal Exp Number PrimaryExp UnaryExp MulExp AddExp RelExp EqExp LOrExp LAndExp
%type <cond> Cond

%type <fundef> FuncDef
%type <fundefarglist> FuncFParams
%type <fundefarg> FuncFParam FuncFParamArray FuncFParamOne

%type <arglist> FuncRParams

%type <block> Block BlockItems
%type <stmt> BlockItem Stmt
%%
CompUnit: CompUnit Decl { 
            $$->context.push_back($2); 
        }
        | CompUnit FuncDef { 
            $$->context.push_back($2); 
        }
        | Decl { 
            root = new NRoot(); 
            $$ = root; 
            $$->context.push_back($2); 
        }
        | FuncDef { 
            root = new NRoot(); 
            $$ = root; 
            $$->context.push_back($2); 
        }
        ;

Decl: ConstDecl SEMI { $$ = $1; }
    | VarDecl SEMI { $$ = $1; }
    ;

ConstDecl: CONST BType ConstDef { 
            $$ = new NDeclare_statement($2);
            $$->child.push_back($3);
        }
        | ConstDecl COMMA ConstDef{
            $$->child.push_back($3);
        }
        ;

BType: INT; { $$ = $1; }

ConstDef: ConstDefSingle { $$ = $1; }
        | ConstDefArray { $$ = $1; }
        ;

ConstDefSingle: IDENT ASSIGN InitVal {
                $$ = new NVarDeclare($1, $3);
            }
            ;

ConstDefArray: DefArrayName ASSIGN InitValArray {
                $$ = new NArrayDeclare($1, $3);
            }
            ;

Def: DefSingle { $$ = $1; }
   | DefArray { $$ = $1; }
   ;

DefSingle: IDENT ASSIGN InitVal {
            $$ = NVarDeclare($1, $3);
        }
        | IDENT{
            $$ = NVarDeclare($1);
        }
        ;

DefArray: DefArrayName ASSIGN InitValArray {
            $$ = NArrayDeclare($1, $3);
        }
        | DefArrayName{
            $$ = NArrayDeclare($1);
        }
        ;

DefArrayName: DefArrayName LSQUARE Exp RSQUARE {
                $$ = $1;
                $$->shape.push_back($3);
            }
            | IDENT LSQUARE Exp RSQUARE {
                $$ = NArrayIdentifier($1);
                $$->shape.push_back($3);
            }
            ;

InitVal: AddExp { $$ = $1; }
       ;

InitValArray: LBRACE InitValArrayInner RBRACE {
                $$ = $2;
            }
            | LBRACE RBRACE{
                $$ = new NArrayInitVal();
            }
            ;

InitValArrayInner: InitValArrayInner COMMA InitValArray {
                    $$ = $1;
                    $$->value.push_back($3);
                }
                | InitValArrayInner COMMA InitVal {
                    $$ = $1;
                    $$->value.push_back(new NArrayInitVal(true, $3));
                }
                | InitValArray {
                    $$ = new NArrayInitVal();
                    $$->value.push_back($1);
                }
                | InitVal {
                    $$ = new NArrayInitVal();
                    $$->value.push_back(new NArrayInitVal(true, $3));
                }
                ;

FuncDef: FuncType IDENT LPAREN RPAREN Block {
            $$ = new NFunctionDefine($1, $2, new NFunctionCallArgList(), $5);
        }
        | FuncType IDENT LPAREN FuncFParams RPAREN Block {
            $$ = new NFunctionDefine($1, $2, $4, $6);
        }
        ;

FuncType: INT { $$ = $1; }
        | VOID { $$ = $1; }
        ;

FuncFParams: FuncFParams COMMA FuncFParam {
                $$ = $1;
                $$->list.push_back($3);
            }
            | FuncFParam{
                $$ = new NFunctionDefineArgList();
                $$->ilst.push_back($1);
            }
            ;

FuncFParam: FuncFParamOne { $$ = $1; }
          | FuncFParamArray { $$ = $1; }
          ;

FuncFParamOne: BType IDENT { $$ = new NFunctionDefineArg($1, $2); }
            ;

FuncFParamArray: BType IDENT LSQUARE RSQUARE {
                    $$ = new NFunctionDefineArg($1, 
                        new NArrayIdentifier($2));
                    $$->name->shape.push_back(new NNumber(1));
                }
                | FuncFParamArray LSQUARE Exp RSQUARE{
                    $$ = $1;
                    $$->name->shape.push_back($3);
                }
                ;

FuncRParams: FuncRParams COMMA AddExp {
                $$ = $1;
                $1->list.push_back($3);
            }
            | AddExp {
                $$ = new NArgList();
                $$->list.push_back($1);
            }
            ;

Block: LBRACE RBRACE
     | LBRACE BlockItems RBRACE
     ;

BlockItems: BlockItem
          | BlockItems BlockItem
          ;

BlockItem: Decl
         | stmt
         ;

Stmt: LVal ASSIGN Exp SEMI
    | Exp SEMI
    | SEMI
    | Block
    | IF LPAREN Cond RPAREN Stmt SEMI
    | IF LPAREN Cond RPAREN Stmt ELSE Stmt SEMI
    | WHILE LPAREN Cond RPAREN Stmt 
    | BREAK SEMI
    | CONTINUE SEMI
    | RETURN SEMI
    | RETURN Exp SEMI
    ;

Exp: AddExp
   | CommaExpr
   ;

CommaExpr: AddExp COMMA AddExp
         | CommaExpr COMMA AddExp
         ;

Cond: LOrExp
    ;

ArrayItem: LVal LSQUARE Exp RSQUARE
         | ArrayItem LSQUARE Exp RSQUARE
         ;

LVal: IDENT
    | ArrayItem
    ;

PrimaryExp: LPAREN Exp RPAREN
          | LVal
          | Number
          ;

Number: INTEGER
      ;

UnaryOp: PlusOp
       | NOT
       ;

MulOp: MUL 
     | DIV
     | MOD
     ;

PlusOp: PLUS
      | MINUS
      ;

RelOp: LT
     | LQ
     | GT
     | GQ
     ;

EqOp: EQ
    | NQ
    ;

UnaryExp: PrimaryExp
        | IDENT LPAREN RPAREN
        | IDENT LPAREN FuncRParams RPAREN
        | UnaryOp UnaryExp
        ;

MulExp: UnaryExp
      | MulExp MulOp UnaryExp
      ;

AddExp: MulExp
      | AddExp PlusOp MulExp
      ;

RelOp: AddExp
     | RelExp RelOp AddExp
     ;

EqExp: RelExp
     | EqExp EqOp RelExp
     ;

LAndExp: EqExp
       | LAndExp AND EqExp
       ;

LOrExp: LAndExp
      | LOrExp OR LAndExp
      ;

%%

