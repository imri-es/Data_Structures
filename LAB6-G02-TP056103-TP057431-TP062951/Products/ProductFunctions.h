//
// Created by momun on 7/26/2022.
//

#ifndef PRODUCTFUNCTIONS_H
#define PRODUCTFUNCTIONS_H

#include "ProductNode.h"
using namespace std;


class ProductFunctions {
public:
    void declareData();
    void printList();
    void append( Product new_data);
    int generateID();
    void getProductData(int *id, string *name, int *price);
    bool checkId(int id, Product *product);

};


#endif //DSTR_PRODUCTFUNCTIONS_H
