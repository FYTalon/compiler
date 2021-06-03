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

    string *str;
    NCondition* cond;
}

%token <str> INTEGER IDENTIFIER
%token <token> IF ELSE WHILE BREAK CONTINUE RETURN 
%token <token> CONST INT VOID
%token <token> ASSIGN EQ NQ LT LQ GT GQ AND OR NOT PLUS MINUS MUL DIV MOD
%token <token> LPAREN RPAREN LSQUARE RSQUARE LBRACE RBRACE COMMA SEMI

%type <root> CompUnit

%type <declare_statement> Decl ConstDecl VarDecl
%type <declare> ConstDef ConstDefSingle ConstDefArray Def DefSingle DefArray

%type <token> BType
%type <ident> IDENT LVal

%type <array_identifier> DefArrayName ArrayItem
%type <array_init_val> InitValArray InitValArrayInner

%type <token> UnaryOp MulOp PlusOp RelOp EqOp
%type <expr> InitVal Exp Number PrimaryExp UnaryExp MulExp AddExp RelExp EqExp LOrExp LAndExp FunctionCall
%type <cond> Cond

%type <fundef> FuncDef
%type <fundefarglist> FuncFParams
%type <fundefarg> FuncFParam FuncFParamArray FuncFParamOne

%type <arglist> FuncRParams

%type <block> Block BlockItems
%type <stmt> BlockItem Stmt AssignStmt IfStmt WhileStmt BreakStmt ContinueStmt ReturnStmt
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
            $$->context.push_back($1); 
        }
        | FuncDef { 
            root = new NRoot(); 
            $$ = root; 
            $$->context.push_back($1); 
        }
        ;

Decl: ConstDecl SEMI { $$ = $1; }
    | VarDecl SEMI { $$ = $1; }
    ;

VarDecl : BType Def {
            $$ = new NDeclareStatement($1);
            $$->child.push_back($2);
        }
        | VarDecl COMMA Def {
            $$ = $1;
            $$->child.push_back($3);
        }

ConstDecl: CONST BType ConstDef { 
            $$ = new NDeclareStatement($2);
            $$->child.push_back($3);
        }
        | ConstDecl COMMA ConstDef{
            $$ = $1;
            $$->child.push_back($3);
        }
        ;

BType: INT { $$ = $1; }
        ; 

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
                    $$->value.push_back(new NArrayInitVal(true, $1));
                }
                ;

FuncDef : BType IDENT LPAREN RPAREN Block {
            $$ = new NFunctionDefine($1, $2, new NFunctionCallArgList(), $5);
        }
        | BType IDENT LPAREN FuncFParams RPAREN Block {
            $$ = new NFunctionDefine($1, $2, $4, $6);
        }
        | VOID IDENT LPAREN RPAREN Block {
            $$ = new NFunctionDefine($1, $2, new NFunctionCallArgList(), $5);
        }
        | VOID IDENT LPAREN FuncFParams RPAREN Block {
            $$ = new NFunctionDefine($1, $2, $4, $6);
        }
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

Block: LBRACE RBRACE { $$ = new NBlock(); }
     | LBRACE BlockItems RBRACE { $$ = $2; }
     ;

BlockItems: BlockItem { $$ = new NBlock(); $$->stmts.push_back($1); }
          | BlockItems BlockItem { $$ = $1; $$->stmts.push_back($2); }
          ;

BlockItem: Decl { $$ = $1; }
         | Stmt { $$ = $1; }
         ;

Stmt: AssignStmt { $$ = $1; }
    | Exp SEMI { $$ = new NEval($1); }
    | SEMI { $$ = new NVoid(); }
    | Block { $$ = $1; }
    | IfStmt { $$ = $1; }
    | WhileStmt { $$ = $1; }
    | BreakStmt { $$ = $1; }
    | ContinueStmt { $$ = $1; }
    | ReturnStmt { $$ = $1; }
    ;

AssignStmt: LVal ASSIGN Exp SEMI { $$ = new NAssignment($1, $3); }

IfStmt :  IF LPAREN Cond RPAREN Stmt SEMI {
            $$ = new NIfElse($3, $5, new NVoid());
        }
        | IF LPAREN Cond RPAREN Stmt ELSE Stmt SEMI{
            $$ = new NIfElse($3, $5, $7);
        }

WhileStmt : WHILE LPAREN Cond RPAREN Stmt {
                $$ = new NWhile($3, $5);
            }

BreakStmt : BREAK SEMI { $$ = new NBreak(); }
ContinueStmt : CONTINUE SEMI { $$ = new NContinue(); }

ReturnStmt :  RETURN SEMI { $$ = new NReturn(); }
            | RETURN Exp SEMI { $$ = new NReturn($2); }

Exp : AddExp { $$ = $1; }
    ;

Cond: LOrExp { $$ = new NConditionExpression($1); }
    ;

ArrayItem: LVal LSQUARE Exp RSQUARE { 
            $$ = new NArrayIdentifier($1); 
            $$->shape.push_back($3);
        }
        | ArrayItem LSQUARE Exp RSQUARE {
            $$ = $1;
            $$->shape.push_back($3);
        }
        ;

LVal: IDENT { $$ = $1; }
    | ArrayItem { $$ = $1; }
    ;

PrimaryExp: LPAREN Exp RPAREN {
            $$ = $2;
        }
        | LVal {
            $$ = $1;
        }
        | Number {
            $$ = $1;
        }
        ;

Number: INTEGER { $$ = new NNumber(*$1); }
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

UnaryExp: PrimaryExp { $$ = $1; }
        | UnaryOp UnaryExp { $$ = new NUnaryExpression($1, $2); }
        | FunctionCall { $$ = $1; }
        ;

FunctionCall: IDENT LPAREN RPAREN {
                $$ = new NFunctionCall($1, new NArgList());
            }
            | IDENT LPAREN FuncRParams RPAREN {
                $$ = new NFunctionCall($1, $3);
            }
        

MulExp: UnaryExp { $$ = $1; }
      | MulExp MulOp UnaryExp { $$ = new NBinaryExpression($1, $2, $3); }
      ;

AddExp: MulExp { $$ = $1; }
      | AddExp PlusOp MulExp { $$ = new NBinaryExpression($1, $2, $3); }
      ;

RelExp: AddExp { $$ = $1; }
     | RelExp RelOp AddExp { $$ = new NBinaryExpression($1, $2, $3); }
     ;

EqExp: RelExp { $$ = $1; }
     | EqExp EqOp RelExp { $$ = new NBinaryExpression($1, $2, $3); }
     ;

LAndExp: EqExp { $$ = $1; }
       | LAndExp AND EqExp { $$ = new NBinaryExpression($1, $2, $3); }
       ;

LOrExp: LAndExp { $$ = $1; }
      | LOrExp OR LAndExp { $$ = new NBinaryExpression($1, $2, $3); }
      ;

IDENT: IDENTIFIER { $$ = new NIdentifier($1); }
%%

