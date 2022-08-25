
#include <iostream>
#include <cstring>

#ifndef LOGINPAGE_H
#define LOGINPAGE_H
using namespace std;


class LoginPage {

public:
    LoginPage();
    void getLogin(string *login, string *password);
    int checkLogin(string *login, string *password);
    void LoginMenu();
};


#endif //LOGINPAGE_H