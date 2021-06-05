%{
#include <string>
#include "node.h"
#include "parser.hpp"
using namespace std;

#define SAVE       yylval.str = new string(yytext, yyleng)
#define TOKEN(t)   (yylval.token = t)
#define SKIP for(auto i : string(yytext_ptr)) { if(i == '\n') yylineno++; }
#define CHANGE2LINENO *yy_cp = yy_hold_char;yy_hold_char='(';yy_cp--;yyleng--;yy_c_buf_p--;*yy_c_buf_p='_';yy_c_buf_p--;*yy_c_buf_p='_';yy_c_buf_p--;*yy_c_buf_p='E';yy_c_buf_p--;*yy_c_buf_p='N';yy_c_buf_p--;*yy_c_buf_p='I';yy_c_buf_p--; *yy_c_buf_p='L'; yy_c_buf_p--; *yy_c_buf_p='_'; yy_c_buf_p--; *yy_c_buf_p='_'; yy_c_buf_p--; return IDENTIFIER;
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
\r                                  yylineno++;
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


"starttime"[ \t\n]*"("              SKIP; yylval.str = new string("_sysy_starttime"); CHANGE2LINENO;
"stoptime"[ \t\n]*"("               SKIP; yylval.str = new string("_sysy_stoptime"); CHANGE2LINENO;
"__LINE__"                          yylval.str = new string(to_string(yyget_lineno())); return DINTEGER;

[a-zA-Z_][a-zA-Z_0-9]*              SAVE; return IDENTIFIER;
[1-9][0-9]*                         SAVE; return DINTEGER;
"0"[0-7]*                           SAVE; return OINTEGER;
"0x"[0-9A-Fa-f]+                    SAVE; return HINTEGER;
"0X"[0-9A-Fa-f]+                    SAVE; return HINTEGER;

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