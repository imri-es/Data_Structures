// LAB6-G02-TP056103-TP057431-TP062951.cpp : Defines the entry point for the application.
//

#include "Headers/DSTR.h"
#include "Headers/LoginPage.h"
#include "Customers/CustomerNode.h"
#include "Customers/CustomerFunctions.h"
#include "Orders/OrderFunctions.h"
#include "Products/ProductFunctions.h"

using namespace std;



int main() {



    ProductFunctions PF;
    PF.declareData();

    CustomerFunctions CF;
    CF.declareData();

    OrderFunctions OF;
    OF.declareData();

    LoginPage LP;
    LP.LoginMenu();

}

