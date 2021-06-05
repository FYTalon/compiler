#include "ir.h"

NRoot* root;


void generate(){
    root->generate_ir();
}

int main(int argc, char *argv[]){
    freopen(argv[3], "r", stdin);
    Eeyore = fopen(argv[5], "w");
    yyparse();
    generate();
    fclose(Eeyore);
}