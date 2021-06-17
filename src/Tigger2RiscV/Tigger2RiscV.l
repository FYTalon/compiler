%option prefix="rr"
%option noyywrap
%{
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include "Tigger2RiscV.tab.hpp"
using namespace std;

#define SAVE            rrlval.str = new string(rrtext, rrleng)
#define TOKEN(t)        (rrlval.token = t)
#define SKIP for(auto i : string(yytext_ptr)) { if(i == '\n') rrlineno++; }
%}

%%

\/\/.*\n?               SKIP;
[ ]                     ;
\n                      rrlineno++;
\r                      rrlineno++;
\t                      ;

"end"                   return TOKEN(TEND);
"call"                  return TOKEN(TCALL);
"if"                    return TOKEN(TIF);
"goto"                  return TOKEN(TGOTO);
"return"                return TOKEN(TRETURN);
"malloc"                return TOKEN(TMALLOC);
"store"                 return TOKEN(TSTORE);
"load"                  return TOKEN(TLOAD);
"loadaddr"              return TOKEN(TLOADADDR);

"v"[0-9]+               SAVE; return TVAR;
"s"[0-9]+               SAVE; return TREG;
"a"[0-9]+               SAVE; return TREG;
"t"[0-9]+               SAVE; return TREG;
"l"[0-9]+               SAVE; return TLABEL;
"x0"                    SAVE; return TREG;

[0-9]+                  SAVE; return TINTEGER;
"-"[0-9]+               SAVE; return TINTEGER;

"f_"[a-zA-Z_][a-zA-Z_0-9]*      SAVE; return TFUNCIDENT;


"="                     SAVE; return TASSIGN;
"=="                    SAVE; return TEQ;
"!="                    SAVE; return TNQ;
"<"                     SAVE; return TLT;
"<="                    SAVE; return TLQ;
">"                     SAVE; return TGT;
">="                    SAVE; return TGQ;
"&&"                    SAVE; return TAND;
"||"                    SAVE; return TOR;
"!"                     SAVE; return TNOT;
"+"                     SAVE; return TPLUS;
"-"                     SAVE; return TMINUS;
"*"                     SAVE; return TMUL;
"/"                     SAVE; return TDIV;
"%"                     SAVE; return TMOD;

"("                     return TOKEN(TLPAREN);
")"                     return TOKEN(TRPAREN);
"["                     return TOKEN(TLSQUARE);
"]"                     return TOKEN(TRSQUARE);
"{"                     return TOKEN(TLBRACE);
"}"                     return TOKEN(TRBRACE);
":"                     return TOKEN(TCOLON);

.                       printf("UNKNOW TOKEN!\n%s\n", rrtext); yyterminate();
%%