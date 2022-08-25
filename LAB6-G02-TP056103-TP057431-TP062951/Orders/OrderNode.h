

#ifndef ORDERNODE_H
#define ORDERNODE_H
#include <iostream>
using namespace std;


class Order{
public:
    int OrdeID;
    int day, month,  year;
    int prodID;
    string prodName;
    int prodPrice;
    int qty;
    int totalAmnt;
    int customerID;
    string custName;
    string custAddress;
    string custPhoneNum;
    string orderStatus;
};


class OrderNode {
public:
    Order data;
    OrderNode *next;
};


#endif //ORDERNODE_H
