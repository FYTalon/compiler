#include "ir.h"

NRoot* root;

void generate(){
    root->generate_ir();
}

int main(){
    yyparse();
    generate();
}