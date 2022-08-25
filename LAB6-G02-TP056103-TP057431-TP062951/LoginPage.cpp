
#include "Headers/LoginPage.h"
#include "Headers/SalesExecutive.h"
#include "Headers/Admin.h"
#include <iostream>

SalesExecutive SE;
Admin AM;

LoginPage::LoginPage(){}
void LoginPage::getLogin(string *login, string *password) {
    
    cout << " ---To exit, enter 0 anywhere---\n Enter username: ";
    cin >> *login;
    if (*login == "0")exit(1);
    cout << "Enter password: ";
    cin >> *password;
}

int LoginPage::checkLogin(string *login, string *password) {
    //checking function
    int checkResult = 0;
    if (*login == "a" || *password == "a") {
        checkResult = 2;
    } else if (*login == "s" || *password == "s") {
        checkResult = 1;
    } else if (*login == "0" || *password == "0") {
        checkResult = -1;
    }
    return checkResult;
}

void LoginPage::LoginMenu() {
    string login, password;
    while (true) {
        getLogin(&login, &password);
        int accountType = checkLogin(&login, &password);
        switch (accountType) {
            case 0:
                system("CLS");
                cout << "Wrong username or password, please try again!\n"<<endl;
                break;
            case 1:
                SE.SalesMenu();
                break;
            case 2:
                AM.AdminMenu();
                break;
            case -1:
                exit(0);
        }
    }
}