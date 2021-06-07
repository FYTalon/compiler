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
"var"                   return TOKEN(EVARDEF);
"end"                   return TOKEN(EEND);
"call"                  return TOKEN(ECALL);
"param"                 return TOKEN(EPARAM);
"if"                    return TOKEN(EIF);
"goto"                  return TOKEN(EGOTO);
"return"                return TOKEN(ERETURN);

"T"[0-9]+               zzlval.var = new TVar('T', atoi(zztext + 1)); return EVAR;
"t"[0-9]+               zzlval.var = new TVar('t', atoi(zztext + 1)); return EVAR;
"p"[0-9]+               zzlval.var = new TVar('p', atoi(zztext + 1)); return EVAR;
"l"[0-9]+               zzlval.var = new TVar('l', atoi(zztext + 1)); return ELABEL;
[0-9]+                  SAVE; return EINTEGER;
"-"[0-9]+               SAVE; return EINTEGER;

"f_"[a-zA-Z_][a-zA-Z_0-9]*      SAVE; return EFUNCIDENT;


"="                     SAVE; return EASSIGN;
"=="                    SAVE; return EEQ;
"!="                    SAVE; return ENQ;
"<"                     SAVE; return ELT;
"<="                    SAVE; return ELQ;
">"                     SAVE; return EGT;
">="                    SAVE; return EGQ;
"&&"                    SAVE; return EAND;
"||"                    SAVE; return EOR;
"!"                     SAVE; return ENOT;
"+"                     SAVE; return EPLUS;
"-"                     SAVE; return EMINUS;
"*"                     SAVE; return EMUL;
"/"                     SAVE; return EDIV;
"%"                     SAVE; return EMOD;

"("                     return TOKEN(ELPAREN);
")"                     return TOKEN(ERPAREN);
"["                     return TOKEN(ELSQUARE);
"]"                     return TOKEN(ERSQUARE);
"{"                     return TOKEN(ELBRACE);
"}"                     return TOKEN(ERBRACE);
":"                     return TOKEN(ECOLON);

.                       printf("UNKNOW TOKEN!\n%s\n", zztext); yyterminate();
%%