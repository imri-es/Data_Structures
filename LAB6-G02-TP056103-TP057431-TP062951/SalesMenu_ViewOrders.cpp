

#include "Headers/SalesMenu_ViewOrders.h"
#include "Orders/OrderFunctions.h"
#include "Headers/SalesMenu_NewPurchase.h"
#include "Products/ProductFunctions.h"
#include "Customers/CustomerFunctions.h"
#include "Headers/Validate.h"

OrderFunctions OF_S;
SalesMenu_NewPurchase SMN_S;
ProductFunctions PF_S;
CustomerFunctions CF_S;
Validate VA_S;

void changeProduct(int updId, Order *order){
    Order updOrder = *order;
    updOrder.prodID = SMN_S.listProducts();
    if (updOrder.prodID == 0){
        return;
    }
    PF_S.getProductData(&updOrder.prodID, &updOrder.prodName, &updOrder.prodPrice);
    cout << "\nEnter quantity:  ";
    cin >> updOrder.qty;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "\nInvalid input, try again\nEnter quantity: ";
        cin >> updOrder.qty;
    }
    updOrder.totalAmnt = updOrder.prodPrice * updOrder.qty;
    OF_S.update_data(updId,updOrder);
    /*OF_S.append( updOrder);*/

}
void changeQuantity(int updId, Order *order){
    Order updOrder = *order;
    cout << "\nEnter quantity:  ";
    cin >> updOrder.qty;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "\nInvalid input, try again\nEnter quantity: ";
        cin >> updOrder.qty;
}
    updOrder.totalAmnt = updOrder.prodPrice * updOrder.qty;
    OF_S.update_data(updId,updOrder);
    cout << "\nStatus of order" << updOrder.OrdeID << "is successfully updated!";
}
void changeCustomer(int updId, Order *order){
    Order updOrder = *order;
    updOrder.customerID = SMN_S.getCust();
    CF_S.checkId(&updOrder.customerID, &updOrder.custName,&updOrder.custAddress,&updOrder.custPhoneNum);
    OF_S.update_data(updId,updOrder);
}
void changeDate(int updId, Order *order){
    int x;
    Order updOrder = *order;
    while (x != 0) {
        x = SMN_S.getDate(&updOrder.day, &updOrder.month, &updOrder.year);
    }
    OF_S.update_data(updId,updOrder);
}

void changeStatus(int updId, Order *order) {
    string input;
    Order updOrder = *order;
    cout << "\nUpdating the first order in the queue";
    cout << "\nID   Status\tDate of Order\tProduct Name\tPrice\tQuantity   Total   Customer Name  Address\tPhone Number\n";
    cout << updOrder.OrdeID << "   " << updOrder.orderStatus << "\t" << updOrder.day << "-" << updOrder.month << "-" << updOrder.year << "\t" << updOrder.prodName << "\t" << updOrder.prodPrice << "\t" << updOrder.qty << "\t   " << updOrder.totalAmnt << "\t   " << updOrder.custName << "\t  " << updOrder.custAddress << "\t" << updOrder.custPhoneNum << "\n";
    updOrder.orderStatus = "Completed";
    OF_S.update_data(updId, updOrder);
    cout << "\nStatus of order with ID " << updOrder.OrdeID << " is successfully updated!\nEnter 0 to go back: ";
    cin >> input;
}

int parameterChoice(){
    int choice;
    cout << "\n1. Product\n2. Quantity\n3. Customer\n4. Date\n0. Go Back\n\nChoose parameter to modify: ";
    cin >> choice;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "\nInvalid input, try again\n1. Product\n2. Quantity\n3. Customer\n4. Date\n0. Go Back\n\nChoose parameter to modify: ";
        cin >> choice;
    }
    return choice;

}

int parameterChoiceSearch(){
    int choice;
    cout << "\n1. Order ID\n2. Date\n3. Customer Name\n4. Customer Address\n5. Customer Phone Number\n6. Product Name\n7. Product Price\n8. Quantity\n9. Total Amount\n0. Go Back\n\nChoose parameter to search: ";
    cin >> choice;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "\nInvalid input, try again\n1. Order ID\n2. Date\n3. Customer Name\n4. Customer Address\n5. Customer Phone Number\n6. Product Name\n7. Product Price\n8. Quantity\n9. Total Amount\n0. Go Back\n\nChoose parameter to search: ";
        cin >> choice;
    }
    return choice;

}

int SalesMenu_ViewOrders::modifyOrderChoice(int param){
    int modifyOrd;
    Order order;
    while(true){
            OF_S.printList();
            cout << "\n0. Go Back\nChoose order ID to modify: ";
            cin >> modifyOrd;
            while (cin.fail()) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "\nInvalid input, try again\n0. Go Back\nChoose order ID to modify: ";
                cin >> modifyOrd;
            }

        if (modifyOrd == 0){
            return 9;
        }

        else if (OF_S.checkId(modifyOrd, &order)){
            int choice = parameterChoice();
            switch (choice){
                case 1: changeProduct(modifyOrd, &order);break;
                case 2: changeQuantity(modifyOrd, &order);break;
                case 3: changeCustomer(modifyOrd, &order);break;
                case 4: changeDate(modifyOrd, &order);break;
                case 0: system("CLS"); break;
            }
            system("CLS");
            cout << "Order with ID " << modifyOrd << " is successfully updated!\n";
        }
    }
}

void sortOrders(){
    string input;
    OF_S.sort();
    OF_S.printList();
    cout << "Enter 0 to go back: ";
    cin >> input;
   //first function here is to accept which field to sort by
   //next sorting will be made with a help of sorting algorithms
   //function to sort by id will be written and declared at the beginning of print function
   //for example i did sort by date, linked list is changed and then displayed in that way
   //after that i did sorting by
}

void updateOrder(){
    Order order2;
    int modifyStatus = OF_S.getQueue();
    if (modifyStatus == -1){
        cout << "All orders in priority are already updated!";
        return;
    }
    OF_S.checkId(modifyStatus, &order2);
    changeStatus(modifyStatus, &order2);
}

bool SalesMenu_ViewOrders::viewAllOrders() {
    int choice;
    while(true) {
        system("CLS");
        OF_S.printList();
        cout << "\n1. Update record by priority\n2. Modify records\n3. Sort view\n4. Search record\n\n9. Main Menu\n0. Exit\nEnter your choice: ";
        cin >> choice;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            system("CLS");
            cout << "\nInvalid input, try again\n1. Update record by priority\n2. Modify records\n3. Sort view\n4. Search record\n\n9. Main Menu\n0. Exit\nEnter your choice: ";
            cin >> choice;
        }
        switch (choice) {
            case 1:
                system("CLS");
                updateOrder(); break;
            case 2:
                system("CLS");
                choice = modifyOrderChoice(1);break;
            case 3:
                system("CLS");
                sortOrders();break;
            case 4:
                system("CLS");
                searchOrder();break;
            case 9:
                system("CLS");
                return false;
            case 0:
                exit(1);
            default:
                system("CLS");
                cout << "Invalid input, try again!\n";
        }
        
        return true;

    }
}
void SalesMenu_ViewOrders::searchOrder(){
    OF_S.printList();
    int choice = parameterChoiceSearch();
    string searchDataStr = "0";
    int searchDataInt = -1;
    if (choice == 1 || choice == 7 ||choice ==8 ||choice == 9){
        cout << "\n0. Go Back\nEnter data to search: ";
        cin >> searchDataInt;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout << "\nInvalid input, try again\n0. Go Back\nEnter data to search: ";
            cin >> searchDataInt;
        }
    }
    else if (choice == 3 ||choice ==4 ||choice == 5 ||choice == 6){
        cout << "\n0. Go Back\nEnter data to search: ";\
        cin.ignore();
        getline(cin, searchDataStr);
        while (!VA_S.validate(searchDataStr, 4)) {
            cout << "\nInvalid input, try again\n0. Go Back\nEnter data to search: ";
            cin.ignore();
            getline(cin, searchDataStr);
        }
    }
    else if (choice == 2){
        int x = 1, day, month, year;
        while (x != 0) {
            x = SMN_S.getDate(&day, &month, &year);
        }
        OF_S.convertDate(&searchDataStr, day, month, year);
    }
    int modify;
    system("CLS");
    OF_S.searchByParameter(choice, searchDataStr, searchDataInt);
    cout << "\nEnter 0 to go back:";
    cin >> modify;
    

}