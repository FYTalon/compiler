#include "ir.h"
#include "Tir.h"

extern FILE *zzin, *yyin;

int main(int argc, char *argv[]){
    yyin = fopen(argv[3], "r");
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
    fclose(zzin);
}