

#ifndef SALESMENU_NEWPURCHASE_H
#define SALESMENU_NEWPURCHASE_H
using namespace std;

class SalesMenu_NewPurchase {
public:
    int listProducts();
    int getDate (int *day, int *month, int *year);
    int getCust();
    void addNewCustomer();
    void addNewPurchaseDetails();
    void addNewProduct();
};


#endif //DSTR_SALESMENU_NEWPURCHASE_H
