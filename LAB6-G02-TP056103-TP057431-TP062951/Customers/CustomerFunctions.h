
#ifndef CUSTOMERFUNCTIONS_H
#define CUSTOMERFUNCTIONS_H
#include "CustomerNode.h"

using namespace std;



class CustomerFunctions {
public:
    void declareData();
    void printList();
    void append( Customer new_data);
    int generateID();

    bool checkId(int *id, string *var, string *address, string *phoneNum);
};


#endif //DSTR_CUSTOMERFUNCTIONS_H
