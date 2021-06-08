#include "tymbol.h"

map<string, string> V2R, R2V, E2V;
int max_id;
int num, curp;
string TContext;
bool inblock;
map<string, bool> ban;
map<string, bool> arr;

const string regs[] = {"s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7", "s8", "s9", "s10", "s11", "t0", "t1", "t2", "t3", "t4", "t5", "t6"};
const int reg_num = 19;

void enter_block(int p){
    inblock = true;
    num = curp = p;
    for(int i = 0; i < num; i++){
        string str = "p" + to_string(i);
        E2V[str] = to_string(i);
        TContext += "store a" + to_string(i) + " " + to_string(i) + "\n";
    }
}

void exit_block(){
    inblock = false;
    for(int i = 0; i < num; i++){
        string str = to_string(i);
        if(!V2R.count(str)) continue ;
        string reg = V2R[str];
        V2R.erase(str);
        R2V.erase(reg);
        arr.erase(str);
    }
}

int get_max(){
    return num;
}

void insert(string *name, int len, bool flag){
    arr[*name] = flag;
    if(inblock){
        E2V[*name] = to_string(num);
        num += len / 4;
    }
    else {
        int id = max_id++;
        E2V[*name] = "v" + to_string(id);
    }
}

void Einit(){
    max_id = 0;
    inblock = false;
    V2R.clear();
    R2V.clear();
    E2V.clear();
}

string get_var(string *name){
    if(E2V.count(*name)) return E2V[*name];
    else return "";
}

void clear_reg(string reg){
    if(!R2V.count(reg)) return ;
    string pre = R2V[reg];
    if(pre.find("v") == pre.npos)
        TContext += (string)"store " + reg + " " + pre + "\n";
    else {
        TContext += (string)"loadaddr " + pre + " s0\n";
        TContext += (string)"s0[0] = " + reg + "\n" ;
    }
    R2V.erase(reg);
    V2R.erase(pre);
}

void melloc_reg(string *name){
    if(V2R.count(*name)) return ;
    int p;
    for(p = 1; p < reg_num; p++)
        if(!R2V.count(regs[p])) break;
    if(p == reg_num){
        p = rand() % (reg_num - 1) + 1;
        while(ban[regs[p]])
            p = rand() % (reg_num - 1) + 1;
        clear_reg(regs[p]);    
    }
    R2V[regs[p]] = *name;
    V2R[*name] = regs[p];
    TContext += (string)"load " + (*name) + " " + regs[p] + "\n";
}

string get_var_reg(string *name){
    string var = get_var(name);
    if(arr[*name]){
        TContext += (string)"loadaddr " + var + " s0\n";
        return "s0";
    }
    melloc_reg(&var);
    return V2R[var];
}

string get_arr_reg(string *name, string *len){
    string var = get_var(name);
    string var_len = get_var(len);
    melloc_reg(&var_len);
    string reg = V2R[var_len];
    clear_reg(reg);
    if(name->find("p") == name->npos){
        TContext += (string)"loadaddr " + var + " s0\n";
    }
    else {
        TContext += (string)"load " + var + " s0\n";
    }
    TContext += reg + " = " + reg + " + s0\n";
    return reg;
}

string get_arr_reg(string *name, int len){
    string var = get_var(name);
    //if(V2R.count(str)) return V2R[str];
    int p;
    for(p = 1; p < reg_num; p++)
        if(!R2V.count(regs[p])) break;
    if(p == reg_num){
        p = rand() % (reg_num - 1) + 1;
        while(ban[regs[p]])
            p = rand() % (reg_num - 1) + 1;
        clear_reg(regs[p]);
    }
    
    string reg = regs[p];
    if(name->find("p") == name->npos){
        TContext += (string)"loadaddr " + var + " s0\n";
    }
    else {
        TContext += (string)"load " + var + " s0\n";
    }
    
    TContext += (string)"s0 = s0 + " + to_string(len) + "\n";
    
    TContext += reg + " = s0\n";
    return reg;
}

void save(){
    for(int i = 1; i < reg_num; i++)
        clear_reg(regs[i]);
}

void clear(){
    V2R.clear();
    R2V.clear();
}