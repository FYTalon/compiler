#include "ir.h"

NRoot* root;

void generate(){
    root->generate_ir();
}

int main(int argc, char *argv[]){
    yyparse();
    generate();
}