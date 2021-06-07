#include "Tnode.h"
#include "Eeyore2Tigger.tab.hpp"

extern TRoot *root;

int main(int argc, char *argv[]){
    freopen(argv[3], "r", stdin);
    Tigger = fopen(argv[5], "w");
    zzparse();
    root->generate_ir();
    fclose(Tigger);
    /*Tigger = stdout;
    zzparse();
    root->generate_ir();*/
}
