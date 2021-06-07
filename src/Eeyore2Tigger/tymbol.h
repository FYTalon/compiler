#ifndef _TYMBOL_H_
#define _TYMBOL_H_
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <cstdlib>

using namespace std;

extern map<string, string> V2R, R2V, E2V;
extern int max_id;
extern int num, curp;
extern string TContext;
extern bool inblock;
extern map<string, bool> ban;

void enter_block(int p);

void exit_block();

int get_max();

void insert(string *name, int len, bool flag);

void Einit();

string get_var(string *name);

void clear_reg(int p);

void clear_reg(string p);

void melloc_reg(string *name);

string get_var_reg(string *name);

string get_arr_reg(string *name, string *len);

string get_arr_reg(string *name, int len);

void save();

void clear();


#endif