%define api.prefix {rr}
%{
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include "Tigger2RiscV.tab.hpp"
using namespace std;

extern int rrdebug;
extern int rrlex();
extern int rrget_lineno();
extern int rrlex_destroy();
extern FILE* RISCV;
void rrerror(const char *s){ printf("Error:%s\natline: %d: \n", s, rrget_lineno()); rrlex_destroy(); exit(1); }

void solve(char *s, string r1, string r2, string r3, string op){
        if(op == "+")
            sprintf(s, "add %s, %s, %s\n", r1.c_str(), r2.c_str(), r3.c_str());

        if(op == "-")
            sprintf(s, "sub %s, %s, %s\n", r1.c_str(), r2.c_str(), r3.c_str());
            
        if(op == "*")
            sprintf(s, "mul %s, %s, %s\n", r1.c_str(), r2.c_str(), r3.c_str());
            
        if(op == "/")
            sprintf(s, "div %s, %s, %s\n", r1.c_str(), r2.c_str(), r3.c_str());
            
        if(op == "%")
            sprintf(s, "rem %s, %s, %s\n", r1.c_str(), r2.c_str(), r3.c_str());
            
        if(op == "<")
            sprintf(s, "slt %s, %s, %s\n", r1.c_str(), r2.c_str(), r3.c_str());
            
        if(op == ">")
            sprintf(s, "sgt %s, %s, %s\n", r1.c_str(), r2.c_str(), r3.c_str());
            
        if(op == "<=")
            sprintf(s, "slt %s, %s, %s\nseqz %s, %s\n", r1.c_str(), r2.c_str(), r3.c_str(), r1.c_str(), r1.c_str());
            
        if(op == ">=")
            sprintf(s, "sgt %s, %s, %s\nseqz %s, %s\n", r1.c_str(), r2.c_str(), r3.c_str(), r1.c_str(), r1.c_str());
            
        if(op == "&&")
            sprintf(s, "snez %s, %s\nsnez s0, %s\nand %s, %s, s0\n", r1.c_str(), r2.c_str(), r3.c_str(), r1.c_str(), r1.c_str());
            
        if(op == "||")
            sprintf(s, "or %s, %s, %s\nsnez %s, %s\n", r1.c_str(), r2.c_str(), r3.c_str(), r1.c_str(), r1.c_str());
            
        if(op == "!=")
            sprintf(s, "xor %s, %s, %s\nsnez %s, %s\n", r1.c_str(), r2.c_str(), r3.c_str(), r1.c_str(), r1.c_str());
            
        if(op == "==")
            sprintf(s, "xor %s, %s, %s\nseqz %s, %s\n", r1.c_str(), r2.c_str(), r3.c_str(), r1.c_str(), r1.c_str());
            
    
}
%}

%union {
    int token;
    std::string* str;
}

%token <token> TEND TCALL TIF TGOTO TRETURN TMALLOC TSTORE TLOAD TLOADADDR
%token <str> TVAR TREG TLABEL TINTEGER TFUNCIDENT
%token <str> TASSIGN TEQ TNQ TLT TLQ TGT TGQ TAND TOR TNOT TPLUS TMINUS TMUL TDIV TMOD
%token <token> TLPAREN TRPAREN TLSQUARE TRSQUARE TLBRACE TRBRACE TCOLON

%type <str> Program GlobalVarDecl FunctionDef root
%type <str> Expressions Expression
%type <str> BinOp OP LogicOp

%%
root: Program {
    fprintf(RISCV, "%s", $1->c_str());
}

Program: Program GlobalVarDecl {
           *$$ = *$1;
           *$$ += *$2;     
       }
       | Program FunctionDef {
           *$$ = *$1;
           *$$ += *$2;
       }
       | {
           $$ = new string("");
       }
       ;

GlobalVarDecl: TVAR TASSIGN TINTEGER {
                $$ = new string("");
                char s[100];
                memset(s, 0, sizeof(s));
                sprintf(s, "  .global   %s\n", $1->c_str());
                *$$ += s;
                memset(s, 0, sizeof(s));
                sprintf(s, "  .section  .sdata\n");
                *$$ += s;
                memset(s, 0, sizeof(s));
                sprintf(s, "  .align    2\n");
                *$$ += s;
                memset(s, 0, sizeof(s));
                sprintf(s, "  .type     %s, @object\n", $1->c_str());
                *$$ += s;
                memset(s, 0, sizeof(s));
                sprintf(s, "  .size     %s, 4\n", $1->c_str());
                *$$ += s;
                memset(s, 0, sizeof(s));
                sprintf(s, "%s:\n", $1->c_str());
                *$$ += s;
                memset(s, 0, sizeof(s));
                sprintf(s, "  .word     %s\n", $3->c_str());
                *$$ += s;
             }
             | TVAR TASSIGN TMALLOC TINTEGER {
                $$ = new string("");
                char s[100];
                memset(s, 0, sizeof(s));
                sprintf(s, "  .comm %s, %s, 4\n", $1->c_str(), $4->c_str());
                *$$ += s;
             }
             ;

FunctionDef: TFUNCIDENT TLSQUARE TINTEGER TRSQUARE TLSQUARE TINTEGER TRSQUARE Expressions TEND TFUNCIDENT {
                $$ = new string("");
                string name = $1->substr(2);
                int STK = (stoi(*$6) / 4 + 1) * 16;
                char s[100];
                memset(s, 0, sizeof(s));
                sprintf(s, "  .text\n");
                *$$ += s;
                memset(s, 0, sizeof(s));
                sprintf(s, "  .align  2\n");
                *$$ += s;
                memset(s, 0, sizeof(s));
                sprintf(s, "  .global %s\n", name.c_str());
                *$$ += s;
                memset(s, 0, sizeof(s));
                sprintf(s, "  .type   %s, @function\n", name.c_str());
                *$$  += s;
                memset(s, 0, sizeof(s));
                sprintf(s, "%s:\n", name.c_str());
                *$$ += s;
                memset(s, 0, sizeof(s));
                sprintf(s, "li s0, -STK\n");
                *$$ += s;
                memset(s, 0, sizeof(s));
                sprintf(s, "add sp, sp, s0\n");
                *$$ += s;
                memset(s, 0, sizeof(s));
                sprintf(s, "li s0, FTK\n");
                *$$ += s;
                memset(s, 0, sizeof(s));
                sprintf(s, "add s0, s0, sp\n");
                *$$ += s;
                memset(s, 0, sizeof(s));
                sprintf(s, "sw ra, 0(s0)\n");
                *$$ += s;
                *$$ += *$8;
                memset(s, 0, sizeof(s));
                sprintf(s, "  .size   %s, .-%s\n", name.c_str(), name.c_str());
                *$$ += s;

                while($$->find("STK") != $$->npos)
                    *$$ = $$->replace($$->find("STK"), 3, to_string(STK));
                while($$->find("FTK") != $$->npos)
                    *$$ = $$->replace($$->find("FTK"), 3, to_string(STK - 4));
            }
           ;

Expressions: Expressions Expression {
                *$$ = *$1 + *$2;
           }
           | {
               $$ = new string("");
           }
           ;

Expression: TREG TASSIGN TREG BinOp TREG {
            char s[100];
            memset(s, 0, sizeof(s));
            solve(s, *$1, *$3, *$5, *$4);
            $$ = new string(s);
          }
          | TREG TASSIGN TREG BinOp TINTEGER {
                $$ = new string("");
                char s[100];
                memset(s, 0, sizeof(s));
                
                    if(*$4 == "+"){
                        int x = stoi(*$5);
                        if(x >= -2048 && x < 2048)
                            sprintf(s, "addi %s, %s, %s\n", $1->c_str(), $3->c_str(), $5->c_str());
                        else {
                            *$$ += "li s0, " + *$5 + "\n";
                            solve(s, *$1, *$3, "s0", "+");
                        }
                    }
                        
                    else if(*$4 == "<"){
                        int x = stoi(*$5);
                        if(x >= -2048 && x < 2048)
                            sprintf(s, "slti %s, %s, %s\n", $1->c_str(), $3->c_str(), $5->c_str());
                        else {
                            *$$ += "li s0, " + *$5 + "\n";
                            solve(s, *$1, *$3, "s0", "<");
                        }
                    }
                        
                    else {
                        *$$ += "li s0, " + *$5 + "\n";
                        solve(s, *$1, *$3, "s0", *$4);
                        
                    }
                
                *$$ += s;
          }
          | TREG TASSIGN OP TREG {
              
                  if(*$3 ==  "-")
                    $$ = new string("");
                    *$$ += "neg " + *$1 + ", " + *$4 + "\n";
                    
                  if(*$3 ==  "!")
                    $$ = new string("");
                    *$$ += "seqz " + *$1 + ", " + *$4 + "\n";
                    
              
          }
          | TREG TASSIGN TREG {
              $$ = new string("");
              *$$ += "mv " + *$1 + ", " + *$3 + "\n";
          }
          | TREG TASSIGN TINTEGER {
              $$ = new string("");
              *$$ += "li " + *$1 + ", " + *$3 + "\n";
          }
          | TREG TLSQUARE TINTEGER TRSQUARE TASSIGN TREG {
              int x = stoi(*$3);
              $$ = new string("");
              if(x >= -2048 && x < 2048)
                *$$ += "sw " + *$6 + ", " + *$3 + "(" + *$1 + ")\n";
              else {
                  *$$ += "li s0, " + *$3 + "\n";
                  *$$ += "add s0, s0, " + *$1 + "\n";
                  *$$ += "sw " + *$6 + ", 0(s0)\n";
                  
              }

          }
          | TREG TASSIGN TREG TLSQUARE TINTEGER TRSQUARE {
              int x = stoi(*$5);
              $$ = new string("");
              if(x >= -2048 && x < 2048)
                *$$ += "lw " + *$1 + ", " + *$5 + "(" + *$3 + ")\n";
              else {
                  *$$ += "li s0, " + *$5 + "\n";
                  *$$ += "add s0, s0, " + *$3 + "\n";
                *$$ += "lw " + *$1 + ", 0(s0)\n";
              }
          }
          | TIF TREG LogicOp TREG TGOTO TLABEL {
              char s[100];
              memset(s, 0, sizeof(s));
              
                  if(*$3 == "<")
                      sprintf(s, "blt %s, %s, .%s\n", $2->c_str(), $4->c_str(), $6->c_str());
                      
                  if(*$3 == ">")
                      sprintf(s, "bgt %s, %s, .%s\n", $2->c_str(), $4->c_str(), $6->c_str());
                      
                  if(*$3 == "<=")
                      sprintf(s, "ble %s, %s, .%s\n", $2->c_str(), $4->c_str(), $6->c_str());
                      
                  if(*$3 == ">=")
                      sprintf(s, "bge %s, %s, .%s\n", $2->c_str(), $4->c_str(), $6->c_str());
                      
                  if(*$3 == "!=")
                      sprintf(s, "bne %s, %s, .%s\n", $2->c_str(), $4->c_str(), $6->c_str());
                      
                  if(*$3 == "==")
                      sprintf(s, "beq %s, %s, .%s\n", $2->c_str(), $4->c_str(), $6->c_str());
                      
              
              $$ = new string(s);
          }
          | TGOTO TLABEL {
              $$ = new string("");
              *$$ += "j ." + *$2 + "\n";
          }
          | TLABEL TCOLON {
              $$ = new string("");
              *$$ += "." + *$1 + ":\n";
          }
          | TCALL TFUNCIDENT {
              string name = $2->substr(2);
              $$ = new string("");
              *$$ += "call " + name + "\n";
          }
          | TRETURN {
              $$ = new string("li s0, FTK\nadd s0, s0, sp\nlw ra, 0(s0)\naddi sp, s0, 4\nret\n");
          }
          | TSTORE TREG TINTEGER {
              int x = stoi(*$3) * 4;
              $$ = new string("");
              if(x >= -2048 && x < 2048)
                *$$ += "sw " + *$2 + ", " + to_string(x) + "(sp)\n";
              else {
                  *$$ += "li s0, " + *$3 + "\n";
                  *$$ += "add s0, s0, sp\n";
                  *$$ += "sw " + *$2 + ", 0(s0)\n";
              }
          }
          | TLOAD TINTEGER TREG {
              int x = stoi(*$2) * 4;
              $$ = new string("");
              if(x >= -2048 && x < 2048)
                *$$ += "lw " + *$3 + ", " + to_string(x) + "(sp)\n";
              else {
                  *$$ += "li s0, " + *$2 + "\n";
                  *$$ += "add s0, s0, sp\n";
                  *$$ += "lw " + *$3 + ", 0(s0)\n";
              }
          }
          | TLOAD TVAR TREG {
              $$ = new string("");
              *$$ += "lui " + *$3 + ", %hi(" + *$2 + ")\n";
              *$$ += "lw " + *$3 + ", %lo(" + *$2 + ")(" + *$3 + ")\n";
          }
          | TLOADADDR TINTEGER TREG {
              int x = stoi(*$2) * 4;
              $$ = new string("");
              if(x >= -2048 && x < 2048)
                *$$ += "addi " + *$3 + ", sp, " + to_string(x) + "\n";
              else {
                  *$$ += "li s0, " + *$2 + "\n";
                  *$$ += "add " + *$3 + ", sp, s0\n";
              }
          }
          | TLOADADDR TVAR TREG {
              $$ = new string("");
              *$$ += "la " + *$3 + ", " + *$2 + "\n";
          }
          ;

BinOp: OP
     | LogicOp
     ;

OP: TNOT
  | TMINUS
  ;

LogicOp: TEQ
       | TNQ
       | TLT
       | TLQ
       | TGT
       | TGQ
       | TAND
       | TOR
       | TPLUS
       | TMINUS
       | TMUL
       | TDIV
       | TMOD
       ;