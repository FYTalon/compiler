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
%}

%union {
    int token;
    NIdentifier* ident;
    NRoot* root;
    NDeclare_statement* declare_statement;
    NDeclare* declare;
    NExpression* expr;
    NFunctionDefine* fundef;
    NArrayInitVal* array_init_val;
    NArrayIdentifier* array_identifier;
    NFunctionCallArgList* fundefarglist;
    NFunctionCallArg* fundefarg;
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
CompUnit: CompUnit Decl
        | CompUnit FuncDef
        | Decl
        | FuncDef
        ;

Decl: ConstDecl SEMI
    | VarDecl SEMI
    ;

ConstDecl: CONST BType ConstDef
         | ConstDecl COMMA ConstDef
         ;

BType: INT;

ConstDef: ConstDefSingle
        | ConstDefArray
        ;

ConstDefSingle: IDENT ASSIGN InitVal
              ;

ConstDefArray: DefArrayName ASSIGN InitValArray
             ;

Def: DefSingle
   | DefArray
   ;

DefSingle: IDENT ASSIGN InitVal
         | IDENT
         ;

DefArray: DefArrayName ASSIGN InitValArray
        | DefArrayName
        ;

DefArrayName: DefArrayName LSQUARE Exp RSQUARE
            | IDENT LSQUARE Exp RSQUARE
            ;

InitVal: AddExp
       ;

InitValArray: LBRACE InitValArrayInner RBRACE
            | LBRACE RBRACE
            ;

InitValArrayInner: InitValArrayInner COMMA InitValArray
                 | InitValArrayInner COMMA InitVal
                 | InitValArray
                 | InitVal
                 ;

FuncDef: FuncType IDENT LPAREN RPAREN Block
       | FuncType IDENT LPAREN FuncFParams RPAREN Block
       ;

FuncType: INT
        | VOID
        ;

FuncFParams: FuncFParams COMMA FuncFParam
           | FuncFParam
           ;

FuncFParam: FuncFParamOne
          | FuncFParamArray
          ;

FuncFParamOne: BType IDENT
             ;

FuncFParamArray: FuncFParamOne LSQUARE RSQUARE
               | FuncFParamArray LSQUARE Exp RSQUARE
               ;

FuncRParams: FuncRParams COMMA AddExp
           | AddExp
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

