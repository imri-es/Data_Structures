

#include "Headers/AdminMenu_ReportGen.h"
#include "Orders/OrderFunctions.h"
#include "Products/ProductFunctions.h"
#include <limits>
#include <ctime>

OrderFunctions OF_A;
ProductFunctions PF_A;

void Simplereport(int year, int month, int type) {
    system("CLS");
    int size = OF_A.generateID(), bulky= 0 , little = 0, total = 0;
    Order orderRep;
    for (int i = 1; i < size; ++i) {

        OF_A.checkId(i, &orderRep);

        if (orderRep.month == month&& orderRep.year == year && type == 1){
            if (orderRep.totalAmnt > 1000)
                bulky++;
            else
                little++;
            total += orderRep.totalAmnt;
        }
        else if (orderRep.year == year&& type == 2){
            if (orderRep.totalAmnt > 1000)
                bulky++;
            else
                little++;
            total += orderRep.totalAmnt;
        }

    }
    cout << "\nBulky orders: " << bulky <<"\nLittle Orders: "<< little << "\nTotal sales: " << total << "\nEnter 0 to go back: " <<endl;
    cin >> bulky;
}


void SalesReport(int year, int month, int type) {
    system("CLS");
    int sizeOfProd = PF_A.generateID(),sizeOfOrd= OF_A.generateID(), ordernum= 0, total = 0, qty = 0, grand = 0;
    Order orderRep;
    Product productRep;
    for (int i = 2; i < sizeOfProd; ++i) {
        ordernum= 0, total = 0, qty = 0;
        PF_A.checkId(i, &productRep);
        for (int j = 1; j < sizeOfOrd; ++j) {
            OF_A.checkId(j, &orderRep);
            if (orderRep.month == month&& orderRep.year == year && type == 1){
                if (orderRep.prodID == productRep.productID){
                    ordernum++;
                    total += orderRep.totalAmnt;
                    grand += orderRep.totalAmnt;
                    qty += orderRep.qty;
                }
            }
            else if (orderRep.year == year && type == 2){
                if (orderRep.prodID == productRep.productID){
                    ordernum++;
                    total += orderRep.totalAmnt;
                    grand += orderRep.totalAmnt;
                    qty += orderRep.qty;
                }
            }
        }
        cout << "\n\t---Item: " << productRep.productName <<"---\n\nTotal Orders: "<< ordernum << "\nTotal Items Sold: "<< qty << "\nTotal sales: " << total << endl;
        }
    cout << "\nGrand Total Orders: "<< sizeOfOrd-1 << "\nGrand Total sales: " << grand <<  "\nEnter 0 to go back: "  << endl;
    cin >> ordernum;

}


void report(int year, int month, int type) {
    int choice;
    while (true) {
        system("CLS");
        cout << "\t\t---Report---\n1. Simple Report\n2. Sales Report\n9. Go Back\n0. Exit\nEnter your choice: ";
        cin >> choice;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            system("CLS");
            cout << "Invalid input, try again\n\t\t---Report---\n1. Simple Report\n2. Sales Report\n9. Go Back\n0. Exit\nEnter your choice: ";
            cin >> choice;
        }

        switch (choice) {
            case 1: {
                Simplereport(year, month,type); break;
            }
            case 2:
                SalesReport(year, month, type);break;
            case 9:
                system("CLS");
                return;
            case 0:
                exit(1);
        }
    }
}



void AdminMenu_ReportGen::reportMenu() {
    system("CLS");
    int choice, type, year, month;
    while (true) {
        cout << "\t\t---Report---\n1. This Month\n2. Previous Month\n3. This Year\n9. Go Back\n0. Exit\nEnter your choice: ";
        cin >> choice;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            system("CLS");
            cout
                    << "\nInvalid input, try again\n\t\t---Report---\n1. This Month\n2. Previous Month\n3. This Year\n9. Go Back\n0. Exit\nEnter your choice: ";
            cin >> choice;
        }
        std::time_t t = std::time(0);   // get time now
        std::tm *now = std::localtime(&t);
        year = now->tm_year + 1900;
        month = now->tm_mon + 1;
        switch (choice) {
            case 1:
                report(year, month, 1);break;
            case 2:
                report(year, month-1, 1);break;
            case 3:
                report(year, month, 2);break;
            case 9:
                return;
            case 0:
                exit(1);
        }

    }
}

