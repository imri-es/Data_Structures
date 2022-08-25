

#include "Headers/SalesMenu_NewPurchase.h"
#include "Customers/CustomerFunctions.h"
#include "Orders/OrderNode.h"
#include "Orders/OrderFunctions.h"
#include "Products/ProductFunctions.h"
#include "Headers/Validate.h"
#include <iostream>
#include <ctime>
#include <cstring>
#include <limits>

CustomerFunctions CF;
OrderFunctions OF;
ProductFunctions PF;
Validate VA;

int SalesMenu_NewPurchase::listProducts() {
    string productName;
    Product prd;
    int prodId = 2;
    while(true){
        PF.printList();
        cout << "\n1. Add new product\n0. Go Back\nChoose product ID from the list above: ";
        cin >> prodId;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout << "\nInvalid input, try again\n1. Add new product\n0. Go Back\nChoose product ID from the list above: ";
            cin >> prodId;
        }
        if (prodId == 1){
            addNewProduct();
        }
        else if (prodId == 0){
            return 0;
        }
        else if (PF.checkId(prodId, &prd )){
            return prodId;
        } else
        cout << "\nInvalid input, try again!\n";
    }

}

int SalesMenu_NewPurchase::getDate(int *day, int *month, int *year) {
    string input;
    cout << "\nEnter date of sale(DD-MM-YYYY)\nEnter 0 to choose today's date:";
    cin >> input;
    std::time_t t = std::time(0);   // get time now
    std::tm *now = std::localtime(&t);
    if (input == "0") {
        *year = now->tm_year + 1900;
        *month = now->tm_mon + 1;
        *day = now->tm_mday;
        return 0;
    }
    try {
        int x;
        char* arrayOfChar = new char[input.length() + 1];
        strcpy(arrayOfChar, input.c_str());
        *day = (arrayOfChar[0] - 48) * 10;
        *day += arrayOfChar[1] - 48;
        *month = (arrayOfChar[3] - 48) * 10;
        *month += arrayOfChar[4] - 48;
        *year = (arrayOfChar[6] - 48) * 1000;
        *year += (arrayOfChar[7] - 48) * 100;
        *year += (arrayOfChar[8] - 48) * 10;
        *year += arrayOfChar[9] - 48;

        const int lookup_table[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (!(*month >= 1 && *month <= 12)) {
            throw x;
        }
        if (!(*day >= 1 && *day <= lookup_table[*month - 1])) {
            throw x;
        }
        if (!(*year >= 1900 && *year <= now->tm_year + 1900)) {
            throw x;
        }
        return 0;

    }
    catch (int x) {
        cout << "Invalid date, follow DD-MM-YYYY format and try again\n";
        return 1;
    }
}

int SalesMenu_NewPurchase::getCust() {

    Customer temp;
    string customerName;
    int choice = 2;
    int custId;

    while (true) {
        CF.printList();
        cout << "\n1. Add new customer\n0. Main Menu\nChoose customer ID from the list above: ";
        cin >> choice;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout << "\nInvalid input, try again\n1. Add new customer\n0. Main Menu\nChoose customer ID from the list above: ";
            cin >> choice;
        }
        //in add new customer then run function with adding new customer
        if (choice == 1){
            addNewCustomer();
        }
        //exits to main menu
        else if (choice == 0){
            return 0;
        }
            //search customer name in the linked list, if there then return customerID
        else if (CF.checkId(&choice, &temp.custName, &temp.custAddress, &temp.custPhoneNum)){
            return choice;
        }else
        cout << "\nInvalid input, try again!\n";
    }


}

void SalesMenu_NewPurchase::addNewCustomer() {
    Customer newCustomer;

    cout << "\nEnter customer name: ";
    cin.ignore();
    getline(cin, newCustomer.custName);
    while (!VA.validate(newCustomer.custName, 1)) {
        cout << "Invalid input, try again\nEnter customer name:";
        cin.ignore();
        getline(cin, newCustomer.custName);
    }

    cout << "\nEnter customer address: ";
    getline(cin, newCustomer.custAddress);
    while (!VA.validate(newCustomer.custAddress, 4)) {
        cout << "Invalid input, try again\nEnter customer address:";
        cin.ignore();
        getline(cin, newCustomer.custAddress);
    }

    cout << "\nEnter customer phone number: ";
    getline(cin, newCustomer.custPhoneNum);
    while (!VA.validate(newCustomer.custPhoneNum, 2)) {
        cout << "Invalid input, try again\nEnter customer address:";
        cin.ignore();
        getline(cin, newCustomer.custPhoneNum);
    }

    newCustomer.id = CF.generateID();
    CF.append(newCustomer);
}

void SalesMenu_NewPurchase::addNewProduct() {
    Product newProduct;
    cout << "\nEnter product name:";
    cin.ignore();
    getline(cin, newProduct.productName);
    if (!VA.validate(newProduct.productName, 3)) {
        cout << "Invalid input, try again!\nEnter product name:";
        cin.ignore();
        getline(cin, newProduct.productName);
    }
    cout << "\nEnter product price:";
    cin >> newProduct.price;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "\nInvalid input, try again\nEnter product price:";
        cin >> newProduct.price;
    }

    newProduct.productID = PF.generateID();
    PF.append(newProduct);
}

void SalesMenu_NewPurchase::addNewPurchaseDetails() {
    system("CLS");
    Order newOrder;
    int x=1;
    newOrder.OrdeID = OF.generateID();
    newOrder.prodID = listProducts();
    if (newOrder.prodID == 0){
        return;
    }
    cout << "\n0. Main Menu\nEnter quantity:  ";
    cin >> newOrder.qty;
    if (newOrder.qty == 0)
        return;
    while (x != 0) {
        x = getDate(&newOrder.day, &newOrder.month, &newOrder.year);
    }
    newOrder.customerID = getCust();
    CF.checkId(&newOrder.customerID, &newOrder.custName,&newOrder.custAddress,&newOrder.custPhoneNum);
    PF.getProductData(&newOrder.prodID, &newOrder.prodName, &newOrder.prodPrice);
    newOrder.totalAmnt = newOrder.prodPrice * newOrder.qty;
    newOrder.orderStatus = "Created";
    OF.append(newOrder);
    system("CLS");
    cout << "Order successfully added!\n\n";

    //date works, need to add it into the orders;



}