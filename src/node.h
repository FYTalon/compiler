#include <cstdui>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

#include <ir.h>

using namespace std;

class Node{
public:
    virtual ~Node();
    virtual void print();
    virtual void generate_ir();
};

class NRoot : public Node{
public:
    vector<Node*>context;
};

class NDeclare : public Node{
public:

};

class NIdentifier : public Node{
public:
    string* name;
};

class NArrayIdentifier : public NIdentifier{
public:
    NIdentifier* name;
    vector<NExpression*> shape;
    NArrayIdentifier(NIdentifier* _name) : name(_name) {}
};

class NArrayInitVal : public NExpression{
public:
    vector<NArrayInitVal*> value;
    NExpression* val;
    bool end;
    NArrayInitVal(bool _end = false, NExpression* _val = NULL) : end(_end), val(_val) {}
};

class NExpression : public Node{
public:
    virtual int eval();
};

class NDeclare_statement : public NStatement{
public:
    vector<NDeclare*>child;
    int type;
    NDeclare_statement(int BType) : type(BType) {}

};

class NVarDeclare : public NDeclare{
public:
    NIdentifier* name;
    NExpression* value;
    NVarDeclare(NIdentifier* identation) : name(identation) { value = NULL; }
    NVarDeclare(NIdentifier* identation, NExpression* expression) : name(identation), value(expression) {}

};

class NArrayDeclare : public NDeclare{
public:
    NArrayIdentifier* name;
    NArrayInitVal* value;
    NArrayDeclare(NArrayIdentifier* identation) : name(identation) { value = NULL;}
    NArrayDeclare(NArrayIdentifier* identation, NArrayInitVal* expression) : name(identation), value(expression) {}
};

class NFunctionDefine : public NDeclare{
public:
    int type;
    NIdentifier* name;
    NFunctionDefineArgList* args;
    NBlock* body;
    NFunctionDefine(int _type, NIdentifier* _name, NFunctionDefineArgList* _args, NBlock* _body) :
    type(_type), name(_name), args(_args), body(_body) {}
};

class NFunctionCallArgList : public NExpression {
public:
    vector<NFunctionDefineArg*> list;
    NFunctionDefineArgList() {}
};

class NFunctionDefineArg : public NExpression{
public:
    int type;
    NIdentifier* name;
    NFunctionDefineArg(int _type, NIdentifier* _name) : 
    type(_type), name(_name) {}
};

