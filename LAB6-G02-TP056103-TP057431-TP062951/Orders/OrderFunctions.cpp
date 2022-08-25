
#include <iostream>
#include <unordered_map>
#include "OrderFunctions.h"

Queue bulky;
Queue small;

OrderNode *headord = NULL;

int sizeOflist =0;


void OrderFunctions::printOne(OrderNode* print) {
    // this function just takes the node as parameter and prints its data
    cout << print->data.OrdeID << "   ";
    cout << print->data.orderStatus << "\t";
    cout << print->data.day << "-" << print->data.month << "-" << print->data.year << "\t";
    cout << print->data.prodName << "\t";
    cout << print->data.prodPrice << "\t";
    cout << print->data.qty << "\t   ";
    cout << print->data.totalAmnt << "\t   ";
    cout << print->data.custName << "\t  ";
    cout << print->data.custAddress << "\t";
    cout << print->data.custPhoneNum << "\n";

}
void reverse(OrderNode** head)
{
    // this function prints the linked list in reverse order
    // will be used in sorting algorithm
    // Initialize current, previous and next pointers
    OrderNode* current = *head;
    OrderNode *prev = NULL, *next = NULL;
    // while it is not empty head
    while (current != NULL) {
        // Store next head
        next = current->next;
        // Reverse current node's pointer
        current->next = prev;
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    // after current head is NULL, loop stops
    // and head is assigned with previous head, which is not NULL, but last one
    *head = prev;
}

int OrderFunctions::getQueue(){
    // this function order ID of the first order in the queue
    int queue = -1;
    // firstly, all bulky orders are checked untill queue with bulky order is empty
    if (bulky.front != NULL) {
        queue = bulky.front->data->data.OrdeID;
        bulky.deQueue();
    }
    // after that small orders are "standing" in the "queue"
    else if(small.front != NULL){
        queue = small.front->data->data.OrdeID;
        small.deQueue();
    }
    return queue;
};




void OrderFunctions::printList() {
    // while list is not empty, keep executing printOne function to print one order data
    OrderNode* printHead = headord;
    cout << "\n---Orders---\nID   Status\tDate of Order\tProduct Name\tPrice\tQuantity   Total   Customer Name  Address\tPhone Number\n";
    while (printHead!= NULL) {
        printOne(printHead);
        printHead = printHead->next;
    }
}
void OrderFunctions::append( Order new_data) {
    // increment size of list
    sizeOflist++;
    //  allocate node
    OrderNode* new_customer = new OrderNode();
    OrderNode *last = headord;
    // Put in the data
    new_customer->data= new_data;
    //  This new node is going to be
    // the last node, so make next of
    // it as NULL
    new_customer->next = NULL;
    //  If the Linked List is empty,
    // then make the new node as headord
    if (headord == NULL)
    {
        //if total amount is greater than 1000, add order to bulky orders Queue
        headord = new_customer;
        if (headord->data.totalAmnt > 1000) {
            bulky.enQueue(headord);
        }
        //otherwise add to small orders Queue
        else
            small.enQueue(headord);

        return;
    }
    //  Else traverse till the last node
    while (last->next != NULL)
    {
        last = last->next;
    }
    //  Change the next of last node

    last->next = new_customer;
    // same procedure, but when orders linked list is not empty
    if (last->next->data.totalAmnt > 1000) {
        bulky.enQueue(last->next);
    }
    else
        small.enQueue(last->next);
}
int OrderFunctions::generateID() {
    //ID generation
    int id = sizeOflist+1;
    return id;
}
void OrderFunctions::convertDate(string *value, int day, int month,  int year){
    //convert data to string
    *value =  to_string(day) + "-" + to_string(month) + "-"+ to_string(year);
}
bool OrderFunctions::searchByParameter(int parameter, string StringToSearch, int IntToSearch) { //LINEAR SEARCHING BECAUSE NOT SORTED
    //here search of order by parameter is made
    int checkInt = 0;
    string checkStr;
    int found = 0;
    OrderNode* current = headord;
    cout << "\n---Orders---\nID\tDate of Order\tProduct Name\tPrice\tQuantity   Total   Customer Name\tAddress\t\tPhone Number\n";
    while (current != NULL)
    {
        switch (parameter) {
            //depending on parameter, assign checking value to subsequent variable
            case 1: checkInt = current->data.OrdeID;break;
            case 2: {
                convertDate(&checkStr, current->data.day, current->data.month,current->data.year);
                break;
            }
            case 3: checkStr = current->data.custName;break;
            case 4: checkStr = current->data.custAddress;break;
            case 5: checkStr = current->data.custPhoneNum;break;
            case 6: checkStr = current->data.prodName;break;
            case 7: checkInt = current->data.prodPrice;break;
            case 8: checkInt = current->data.qty;break;
            case 9: checkInt = current->data.totalAmnt;break;

        }
        // after checking variable is get, check if variable is equals to comparing input from user
        //  if found, current node will be printed with a use of printOne function
        // if not, switch to next node
        if (checkStr.find(StringToSearch) != std::string::npos || checkInt == IntToSearch){
            printOne(current);
            found = 1;
        }
        current = current->next;
    }
    // if not found in the whole linked list
    if (found != 1){
        cout << "\n\t\tNO RECORDS FOUND WITH ENTERED DATA";
        return false;
    }
    //if found, return true
    return true;

}
void OrderFunctions::declareData() {
    //Data Structure Initialization
    Order order1;
    // Assigning values to structures
    order1 = {1,20,06,2022,3,"Sofa \"Classic\"", 820, 1, 820, 4, "Zahir", "London", "0124345161", "Created"};
    //adding structures to the linked list
    append(order1);
    order1 = {2,21,06,2022,2,"Desk \"Modern\"", 1230, 1, 1230, 7, "Jack Ma", "Kelantan", "0125312854", "Created"};
    append(order1);
    order1 = {3,22,06,2022,4,"Sofa \"Modern\"", 960, 1, 960, 6, "Sabina", "Endah", "0128295821","Created"};
    append(order1);
    order1 = {4,23,07,2022,2,"Desk \"Modern\"", 1230, 2, 2460, 3, "Daniel", "Almaty", "0132253214", "Created"};
    append(order1);
    order1 = {5,23,07,2022,5,"Kitchen chair", 370, 5, 1850, 7, "Jack Ma", "Kelantan", "0125312854", "Created"};
    append(order1);
    order1 = {6,25,07,2022,6,"Gaming chair", 450, 2, 900, 5, "Hafiz", "Zagreb", "0125312854", "Created"};
    append(order1);
    order1 = {7,25,07,2022,2, "Desk \"Modern\"", 1230, 2, 2460, 6, "Sabina", "Endah", "0128295821", "Created"};
    append(order1);
    order1 = {8,26,07,2022,6,"Gaming chair", 450, 2, 900, 6, "Sabina", "Endah", "0128295821",  "Created"};
    append(order1);
    order1 = {9,26,07,2022,2,"Desk \"Modern\"", 1230, 5, 6150, 7, "Jack Ma", "Kelantan", "0125312854", "Created"};
    append(order1);
    order1 = {10,29,07,2022,6,"Gaming chair", 450, 2, 900, 3, "Daniel", "Almaty", "0132253214", "Created"};
    append(order1);
    order1 = {11,29,07,2022, 2, "Desk \"Modern\"", 1230, 2, 2460, 4, "Zahir", "London", "0124345161", "Created"};
    append(order1);
    order1 = {12,29,07,2022,5, "Kitchen chair", 370, 2, 740, 4, "Zahir", "London", "0124345161", "Created"};
    append(order1);
    order1 = {13,29,07,2022,5, "Kitchen chair", 370, 20, 7400, 7, "Jack Ma", "Kelantan", "0125312854", "Created"};
    append(order1);



}
struct OrderNode* middle(OrderNode* start, OrderNode* last)
{
    //same function of searching middle value
    if (start == NULL)
        return NULL;

    struct OrderNode* slow = start;
    struct OrderNode* fast = start -> next;

    while (fast != last)
    {
        fast = fast -> next;
        if (fast != last)
        {
            slow = slow -> next;
            fast = fast -> next;
        }
    }
    return slow;
}
bool OrderFunctions::checkId(int id, Order *order) { //BINARY SEARCH FOR FASTER ACCESS

    //same function as in other linked lists in the code
    selectionSort( &headord, sizeOflist,  1, 1);
    struct OrderNode* start = headord;
    struct OrderNode* last = NULL;
    do
    {
        OrderNode* mid = middle(start, last);

        if (mid == NULL)
            return false;

        if (mid -> data.OrdeID == id){
            *order = mid -> data;
            return true;
        }


        else if (mid -> data.OrdeID < id)
            start = mid -> next;

        else
            last = mid;

    } while (last == NULL ||
             last != start);
    // value not present
    return false;
}
bool OrderFunctions::update_data(int OldId, Order newOrd ) {

    // this function is used to update data based on orderID
    struct OrderNode* start = headord;
    struct OrderNode* last = NULL;
    //same binary search is used here
    do
    {
        OrderNode* mid = middle(start, last);
        if (mid == NULL)
            return false;
        if (mid -> data.OrdeID == OldId){
            //if found, replace the node
            mid -> data = newOrd;
            return true;
        }
        else if (mid -> data.OrdeID < OldId)
            start = mid -> next;
        else
            last = mid;

    } while (last == NULL ||
             last != start);
    // value not present
    return false;
}
void OrderFunctions::swapNodes(OrderNode** initial, OrderNode* x,OrderNode*  y)
{
    //swapping two nodes
    // Nothing to do if x and y are same
    if (x==y)
        return;
    // Search for x (keep track of prevX and CurrX
    OrderNode *prevX = NULL, *currX = *initial;
    while (currX && currX != x) {
        prevX = currX;
        currX = currX->next;
    }
    // Search for y (keep track of prevY and CurrY
    OrderNode *prevY = NULL, *currY = *initial;
    while (currY && currY != y) {
        prevY = currY;
        currY = currY->next;
    }
    // If either x or y is not present, nothing to do
    if (currX == NULL || currY == NULL)
        return;

    // If x is not headord of linked list
    if (prevX != NULL)
        prevX->next = currY;
    else // Else make y as new headord
        headord = currY;

    // If y is not headord of linked list
    if (prevY != NULL)
        prevY->next = currX;
    else // Else make x as new headord
        headord = currX;

    // Swap next pointers
    OrderNode* temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;


}
void OrderFunctions::append2(OrderNode** nodeTemp, Order new_data) {
    //temporary linked list
    // 1. allocate node
    OrderNode* new_customer = new OrderNode();
    // Used in step 5
    OrderNode *last = *nodeTemp;
    // 2. Put in the data
    new_customer->data= new_data;
    // 3. This new node is going to be
    // the last node, so make next of
    // it as NULL
    new_customer->next = NULL;
    // 4. If the Linked List is empty,
    // then make the new node as headord
    if (*nodeTemp == NULL)
    {
        *nodeTemp = new_customer;
        return;
    }
    // 5. Else traverse till the last node
    while (last->next != NULL)
    {
        last = last->next;
    }
    // 6. Change the next of last nodes
    last->next = new_customer;
}

int days_from_civil(int y, unsigned m, unsigned d) noexcept {
    // calculating number of days since the date
    static_assert(std::numeric_limits<unsigned>::digits >= 18,
                  "This algorithm has not been ported to a 16 bit unsigned integer");
    static_assert(std::numeric_limits<int>::digits >= 20,
                  "This algorithm has not been ported to a 16 bit signed integer");
    y -= m <= 2;
    const int era = (y >= 0 ? y : y - 399) / 400;
    const unsigned yoe = static_cast<unsigned>(y - era * 400);      // [0, 399]
    const unsigned doy = (153 * (m > 2 ? m - 3 : m + 9) + 2) / 5 + d - 1;  // [0, 365]
    const unsigned doe = yoe * 365 + yoe / 4 - yoe / 100 + doy;         // [0, 146096]
    return era * 146097 + static_cast<int>(doe) - 719468;
}


void OrderFunctions::selectionSort(OrderNode** orderNode, int n, int sortby, int order) {
    // selection sorting
    int i, j;
    // One by one move boundary of
    // unsorted subarray
    OrderNode *temppr = NULL;
    for (i = 0; i < n; i++)
    {
        // Find the minimum element in
        // unsorted array
        OrderNode* min_idx = *orderNode; //id = 0
        OrderNode* loopNode = (*orderNode)->next; //
        for (j = i + 1; j < n; j++) {
            switch (sortby) {
                case 1: {//Order ID
                    if (loopNode->data.OrdeID < min_idx->data.OrdeID)
                        min_idx = loopNode;
                    break;
                }
                case 2: {//Date

                    if (days_from_civil(loopNode->data.year, loopNode->data.month, loopNode->data.day) < days_from_civil(min_idx->data.year, min_idx->data.month, min_idx->data.day) )
                        min_idx = loopNode;
                    break;
                }
                case 3: {//Product Name
                    int n1 = loopNode->data.prodName.length();
                    int n2 = min_idx->data.prodName.length();
                    char* str1 = new char[n1 + 1];
                    char* str2 = new char[n2 + 1];
                    strcpy(str1, loopNode->data.prodName.c_str());
                    strcpy(str2, min_idx->data.prodName.c_str());

                    int result = strcmp(str1, str2);
                    if (result < 0)
                        min_idx = loopNode;
                    break;
                }
                case 4: {//Product Price
                    if (loopNode->data.prodPrice < min_idx->data.prodPrice)
                        min_idx = loopNode;
                    break;
                }
                case 5: {//Quantity
                    if (loopNode->data.qty < min_idx->data.qty)
                        min_idx = loopNode;
                    break;
                }
                case 6: {//Total Amount
                    if (loopNode->data.totalAmnt < min_idx->data.totalAmnt)
                        min_idx = loopNode;
                    break;
                }
            }
            loopNode = loopNode->next;
        }

        swapNodes(&*orderNode, min_idx, *orderNode);
        Order tempor = (*orderNode)->data;
        append2(&temppr, tempor);
        *orderNode = (*orderNode)->next;
    }
    headord = temppr;
    // if order is descending
    if (order == 2)
        reverse(&headord);
}
int OrderFunctions::sort(){

    // selection of parameter and order of sorting
    int choice, order;
    cout << "\n1. Order ID\n2. Date\n3. Product Name\n4. Product Price\n5. Quantity\n6. Total Amount\n0. Go Back\n\nChoose parameter to sort by: ";
    cin >> choice;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "\nInvalid input, try again\n1. Order ID\n2. Date\n3. Product Name\n4. Product Price\n5. Quantity\n6. Total Amount\n0. Go Back\n\nChoose parameter to sort by: ";
        cin >> choice;
    }
    cout << "\n1. Ascending Order\n2. Descending Order\n0. Go Back\n\nChoose order way to display: ";
    cin >> order;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "\nInvalid input, try again\n1. Ascending Order\n2. Descending Order\n0. Go Back\n\nChoose order way to display: ";
        cin >> order;
    }
    // start sorting based on parameters user input
    selectionSort(&headord, sizeOflist, choice, order);
    system("CLS");
    return 0;

}