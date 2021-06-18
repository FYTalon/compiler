#include "ir.h"
#include "Tir.h"
#include "Tigger2RiscV.tab.hpp"

extern FILE *zzin, *yyin, *rrin;
FILE* RISCV;

int main(int argc, char *argv[]){
    yyin = fopen(argv[3], "r");
    Eeyore = fopen("m.eeyore", "w");
    Eeyore = fopen(argv[5], "w");
    yyparse();
    root->generate_ir();
    fclose(Eeyore);
    fclose(yyin);
    /*zzin = fopen("m.eeyore", "r");
    Tigger = fopen("m.tigger", "w");
    zzparse();
    Troot->generate_ir();
    fclose(Tigger);
    fclose(zzin);*/s

    /*zzin = fopen(argv[3], "r");
    Tigger = fopen(argv[5], "w");
    zzparse();
    Troot->generate_ir();
    fclose(Tigger);
    fclose(zzin);*/

    /*rrin = fopen(argv[2], "r");
    RISCV = fopen(argv[4], "w");
    rrparse();
    fclose(rrin);*/

    /*zzin = fopen(argv[2], "r");
    Tigger = fopen("m.tigger", "w");
    zzparse();
    Troot->generate_ir();
    fclose(Tigger);
    fclose(zzin);*/
    /*rrin = fopen("m.tigger", "r");
    RISCV = fopen(argv[4], "w");
    rrparse();
    fclose(rrin);
    fclose(RISCV);*/
}