%{
#include <string>
#include "y.tab.h"
using namespace std;

#define SAVE(t)     yylval.str = new string(yytext, yyleng)
#define TOKEN(t)   (yylval.token = t)
#define SKIP for(auto i : string(yytext_ptr)) { if(i == '\n) yylineno++; }
%}

%option noyywrap

%%

\/\/.*\n?                            SKIP;
"/*"                                {
                                        int c;
                                        while((c = yyinput()) != 0){
                                            if(c == '\n')
                                                yylineno++;
                                            else if(c == '*'){
                                                if((c = yyinput()) == '/')
                                                    break;
                                                else 
                                                    unput(c);
                                            }
                                        }
                                    }
[ ]                                 ;
\n                                  yylineno++;
\t                                  ;
"if"                                return TOKEN(IF);
"else"                              return TOKEN(ELSE);
"while"                             return TOKEN(WHILE);
"break"                             return TOKEN(BREAK);
"continue"                          return TOKEN(CONTINUE);
"return"                            return TOKEN(RETURN);
"const"                             return TOKEN(CONST);
"int"                               return TOKEN(INT);
"void"                              return TOKEN(VOID);

[a-zA-Z_][a-zA-Z_0-9]               SAVE; return IDENTIFIER;
[0-9]+                              SAVE; return INTEGER;
"0x"[0-9A-Fa-f]+                    SAVE; return INTEGER;
"0X"[0-9A-Fa-f]+                    SAVE; return INTEGER;

"="                                 return TOKEN(ASSIGN);
"=="                                return TOKEN(EQ);
"!="                                return TOKEN(NQ);
"<"                                 return TOKEN(LT);
"<="                                return TOKEN(LQ);
">"                                 return TOKEN(GT);
">="                                return TOKEN(GQ);
"&&"                                return TOKEN(AND);
"||"                                return TOKEN(OR);
"!"                                 return TOKEN(NOT);
"+"                                 return TOKEN(PLUS);
"-"                                 return TOKEN(MINUS);
"*"                                 return TOKEN(MUL);
"/"                                 return TOKEN(DIV);
"%"                                 return TOKEN(MOD);

"("                                 return TOKEN(LPAREN);
")"                                 return TOKEN(RPAREN);
"["                                 return TOKEN(LSQUARE);
"]"                                 return TOKEN(RSQUARE);
"{"                                 return TOKEN(LBRACE);
"}"                                 return TOKEN(RBRACE);
","                                 return TOKEN(COMMA);
";"                                 return TOKEN(SEMI);

.                                   printf("UNKNOW TOKEN!\n%s\n", yytext); yyterminate();
%%