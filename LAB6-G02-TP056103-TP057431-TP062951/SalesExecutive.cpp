
#include "Headers/SalesExecutive.h"
#include "Headers/MenuItems.h"
#include <iostream>
#include <limits>
MenuItems MI;

void SalesExecutive::SalesMenu() {
    int choice;
    bool run = true;
    system("CLS");
    do{
        cout << "\t ---Main Menu---" << endl <<"1. New Order\n2. View Orders\n9. Log Out\n0. Exit\n\n Enter your choice: ";
        cin >> choice;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            system("CLS");
            cout << "\nInvalid input, try again\n\t ---Main Menu---" << endl << "1. New Order\n2. View Orders\n9. Log Out\n0. Exit\n\n Enter your choice: ";
            cin >> choice;
        }
        switch (choice) {
            case 1: MI.SalesPage_NewPurchase(); break;
            case 2: MI.SalesPage_ViewOrders(); break;
            case 9: run = false; break;
            case 0: exit(0);

            default:
                system("CLS");
                cout << "\nInvalid input, try again\n";
                break;
        }
    }while(run);



}
#include "Headers/SalesExecutive.h"
