

#ifndef ORDERFUNCTIONS_H
#define ORDERFUNCTIONS_H


#include <iostream>
#include <cstring>
#include "OrderNode.h"
#include "../Headers/OrderQueue.h"
#include "bits-stdc++.h"
using namespace std;


class OrderFunctions {
public:

    void declareData();
    void printList();
    void append( Order new_data);
    int generateID();
    bool searchByParameter(int parameter, string StringToSearch, int IntToSearch);
    bool checkId(int id, Order *order);
    bool update_data(int OldId, Order newOrd );
    void convertDate(string *value, int day, int month,  int year);
    void selectionSort(OrderNode** orderNode, int n, int sortby, int order);
    int sort();
    void swapNodes(OrderNode **initial, OrderNode *x, OrderNode *y);
    void append2(OrderNode **nodeTemp, Order new_data);
    int getQueue();
    void printOne(OrderNode* print);
};


#endif //DSTR_ORDERFUNCTIONS_H
