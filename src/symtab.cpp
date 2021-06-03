#include "symtab.h"

SymTab *head;

void init(){
    head = NULL;
}

void EnterBlock(){
    SymTab* blk = new SymTab();
    blk->pre = head;
    if(head != NULL) head->nxt = blk;
    head = blk;
}

void ExitBlock(){
    head = head->pre;
    delete head->nxt;
}

void insert(string* name, int paranum, int memloc, char type){
    head->tab[*name] = new Symbol(paranum, memloc, type);
}

Symbol* lookup(string* name){
    SymTab* now = head;
    while(now != NULL && now->tab.count(*name) == 0)
        now = now->pre;
    Symbol* ret = new Symbol();
    if(now != NULL) ret = now->tab[*name];
    return ret;
}