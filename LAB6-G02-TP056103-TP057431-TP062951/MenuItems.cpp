
#include "Headers/MenuItems.h"
#include "Headers/SalesMenu_NewPurchase.h"
#include "Orders/OrderFunctions.h"
#include "Headers/SalesMenu_ViewOrders.h"
#include "Headers/AdminMenu_ReportGen.h"
#include <iostream>

AdminMenu_ReportGen AMR;
SalesMenu_NewPurchase SMN;
SalesMenu_ViewOrders SMV;


void MenuItems::SalesPage_NewPurchase() {
    SMN.addNewPurchaseDetails();
}
void MenuItems::SalesPage_ViewOrders() {
    bool run = true;
    while (run){
        run = SMV.viewAllOrders();
    }
}

void MenuItems::AdminPage_ReportGen() {
    AMR.reportMenu();

};