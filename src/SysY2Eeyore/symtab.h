#ifndef _SYMTAB_H_
#define _SYMTAB_H_
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

class Symbol{
public:
    int paranum;
    int memloc;
    char type;
    Symbol(int para, int mem, char t) : paranum(para), memloc(mem), type(t) {}
    Symbol(){
        paranum = 0;
        memloc =  -1;
        type = 'Z';
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
};

extern SymTab* head;

void init();

void EnterBlock();

void ExitBlock();

void insert(string* name, int paranum, int memloc, char type);

Symbol* lookup(string* name);

#endif

