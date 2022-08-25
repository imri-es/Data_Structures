
#include "CustomerFunctions.h"

CustomerNode *head = NULL;
void CustomerFunctions::printList() {
    //function for printing linked list of customers
    // head of customer linked list is assigned to new head so that original head wouldnt change
    //after that element is printed and head is assigned with next head
    // if head is NULL then end (WHILE)
    CustomerNode *printhead = head;
    cout << "\n---Customers---\nID\tName\t\tAddress\t\tPhone Number\n";
    while (printhead != NULL) {
        cout << printhead->data.id << "\t";
        cout << printhead->data.custName << "\t\t";
        cout << printhead->data.custAddress << "\t\t";
        cout << printhead->data.custPhoneNum << "\n";
        printhead = printhead->next;
    }
}
void CustomerFunctions::append( Customer new_data) {
    //allocate node
    CustomerNode* new_customer = new CustomerNode();
    CustomerNode *last = head;
    // Put in the data
    new_customer->data= new_data;
    // This new node is going to be
    // the last node, so make next of
    // it as NULL
    new_customer->next = NULL;
    // 4. If the Linked List is empty,
    // then make the new node as head
    if (head == NULL)
    {
        head = new_customer;
        return;
    }
    // 5. Else traverse till the last node
    while (last->next != NULL)
    {
        last = last->next;
    }
    // 6. Change the next of last node
    last->next = new_customer;
    return;
}
int CustomerFunctions::generateID() {
    // ID generation for customer
    // ID will be generated based on max(last) value in linked list +1
    int id = 1;
    CustomerNode *last = head;
    if (head == NULL){
        return id;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    id = last->data.id;
    id++;
    return id;

}
void CustomerFunctions::declareData() {
    //Data Structure Initialization
    // initializing Customer structs and then assigning values to them and then appending to the linked list
    Customer customer1;
    customer1 = {3, "Daniel", "Almaty", "0132253214"}; append(customer1);
    customer1 = {4, "Zahir", "London", "0124345161"};  append(customer1);
    customer1 = {5, "Hafiz", "Zagreb", "0125312854"}; append( customer1);
    customer1 = {6, "Sabina", "Endah", "01282958212"}; append( customer1);
    customer1 = {7, "Jack Ma", "Kelantan", "0125312854"}; append( customer1);


}
struct CustomerNode* middle(CustomerNode* start, CustomerNode* last)
{
    // this function is for binary searching algorithm, which searches for middle item
    if (start == NULL)
        return NULL;

    struct CustomerNode* slow = start;
    struct CustomerNode* fast = start -> next;

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
bool CustomerFunctions::checkId(int *id, string *var, string *address, string *phoneNum) { //BINARY SEARCH FOR FASTER ACCESS
    // this function searches for customer id using binary search
    //one found, pointers to parameter addresses will be assigned with consequent value
    struct CustomerNode* start = head;
    struct CustomerNode* last = NULL;
    do
    {
        // Find middle
        CustomerNode* mid = middle(start, last);
        // If middle is empty
        if (mid == NULL)
            return false;
        // If value is present at middle
        if (mid -> data.id == *id ){
            *var = mid -> data.custName;
            *address = mid -> data.custAddress;
            *phoneNum = mid -> data.custPhoneNum;
            return true;
        }
            // If value is more than mid
        else if (mid -> data.id < *id)
            start = mid -> next;
            // If the value is less than mid.
        else
            last = mid;
    } while (last == NULL ||
             last != start);
    // value not present
    return false;
}


