//
// Created by momun on 7/26/2022.
//

#ifndef PRODUCTNODE_H
#define PRODUCTNODE_H
#include <iostream>
using namespace std;

struct Product {
    int productID;
    string productName;
    int price;
};

class ProductNode {
public:
    Product data;
    ProductNode *next;
};



#endif //DSTR_PRODUCTNODE_H
