#include "ir.h"
#include "Tir.h"
#include "Tigger2RiscV.tab.hpp"

extern FILE *zzin, *yyin, *rrin;
FILE* RISCV;

int main(int argc, char *argv[]){
    /*yyin = fopen(argv[3], "r");
    Eeyore = fopen("m.eeyore", "w");
    yyparse();
    root->generate_ir();
    fclose(Eeyore);
    fclose(yyin);
    zzin = fopen("m.eeyore", "r");
    Tigger = fopen(argv[5], "w");
    zzparse();
    Troot->generate_ir();
    fclose(Tigger);
    fclose(zzin);*/
    /*zzin = fopen(argv[3], "r");
    Tigger = fopen(argv[5], "w");
    zzparse();
    Troot->generate_ir();
    fclose(Tigger);
    fclose(zzin);*/
    rrin = fopen(argv[3], "r");
    RISCV = fopen(argv[5], "w");
    rrparse();
    fclose(rrin);
}