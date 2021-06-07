%option prefix="zz"
%option noyywrap
%{
#include <string>
#include "Tnode.h"
#include "Eeyore2Tigger.tab.hpp"
using namespace std;

#define SAVE            zzlval.str = new string(zztext, zzleng)
#define TOKEN(t)        (zzlval.token = t)
#define SKIP for(auto i : string(yytext_ptr)) { if(i == '\n') zzlineno++; }
%}

%%

\/\/.*\n?               SKIP;
[ ]                     ;
\n                      zzlineno++;
\r                      zzlineno++;
\t                      ;
"var"                   return TOKEN(VARDEF);
"end"                   return TOKEN(END);
"call"                  return TOKEN(CALL);
"param"                 return TOKEN(PARAM);
"if"                    return TOKEN(IF);
"goto"                  return TOKEN(GOTO);
"return"                return TOKEN(RETURN);

"T"[0-9]+               zzlval.var = new TVar('T', atoi(zztext + 1)); return VAR;
"t"[0-9]+               zzlval.var = new TVar('t', atoi(zztext + 1)); return VAR;
"p"[0-9]+               zzlval.var = new TVar('p', atoi(zztext + 1)); return VAR;
"l"[0-9]+               zzlval.var = new TVar('l', atoi(zztext + 1)); return LABEL;
[0-9]+                  SAVE; return INTEGER;
"-"[0-9]+               SAVE; return INTEGER;

"f_"[a-zA-Z_][a-zA-Z_0-9]*      SAVE; return FUNCIDENT;


"="                     SAVE; return ASSIGN;
"=="                    SAVE; return EQ;
"!="                    SAVE; return NQ;
"<"                     SAVE; return LT;
"<="                    SAVE; return LQ;
">"                     SAVE; return GT;
">="                    SAVE; return GQ;
"&&"                    SAVE; return AND;
"||"                    SAVE; return OR;
"!"                     SAVE; return NOT;
"+"                     SAVE; return PLUS;
"-"                     SAVE; return MINUS;
"*"                     SAVE; return MUL;
"/"                     SAVE; return DIV;
"%"                     SAVE; return MOD;

"("                     return TOKEN(LPAREN);
")"                     return TOKEN(RPAREN);
"["                     return TOKEN(LSQUARE);
"]"                     return TOKEN(RSQUARE);
"{"                     return TOKEN(LBRACE);
"}"                     return TOKEN(RBRACE);
":"                     return TOKEN(COLON);

.                       printf("UNKNOW TOKEN!\n%s\n", zztext); yyterminate();
%%