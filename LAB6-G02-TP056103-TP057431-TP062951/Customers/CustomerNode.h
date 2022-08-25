
#ifndef CUSTOMERNODE_H
#define CUSTOMERNODE_H
#include <iostream>
using namespace std;

struct Customer{
    //customer structure with customers parameters
public:
    int id;
    string custName;
    string custAddress;
    string custPhoneNum;
};


class CustomerNode {
    //definition of customer linked list
public:
    Customer data;
    CustomerNode *next;
};


#endif //CUSTOMERNODE_H
