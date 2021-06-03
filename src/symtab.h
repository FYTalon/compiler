#ifndef _SYMTAB_H_
#define _SYMTAB_H_
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>

class Symbol{
public:
    int paranum;
    int memloc;
    char type;
    Symbol(int para, int mem, char t) : paranum(para), memloc(mem), type(t) {}
    Symbol(){
        paranum = 0;
        memloc =  -1;
        type = 'T';
    }
};

class SymTab{
public:
    SymTab* nxt;
    SymTab* pre;
    map<string, Symbol*> tab;
    SymTab(){
        nxt = NULL;
        tab.clear();
    }
}*head;

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
    delet(head->nxt);
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

#endif

