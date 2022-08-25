//
// Created by momun on 7/26/2022.
//

#include "ProductFunctions.h"
ProductNode *producthead = NULL;

void ProductFunctions::printList() {
    ProductNode *printhead = producthead;
    cout << "\n---Products---\nID\tName\t\t\tPrice\n";
    while (printhead != NULL) {
        cout << printhead->data.productID << "\t";
        cout << printhead->data.productName << "\t\t";
        cout << printhead->data.price << "\n";
        printhead = printhead->next;
    }
}
void ProductFunctions::append(Product new_data) {
    // 1. allocate node
    ProductNode* new_customer = new ProductNode();

    // Used in step 5
    ProductNode *last = producthead;

    // 2. Put in the data

    new_customer->data= new_data;

    // 3. This new node is going to be
    // the last node, so make next of
    // it as NULL
    new_customer->next = NULL;

    // 4. If the Linked List is empty,
    // then make the new node as producthead
    if (producthead == NULL)
    {
        producthead = new_customer;
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
int ProductFunctions::generateID() {
    int id = 1;
    ProductNode *last = producthead;
    if (producthead == NULL){
        return id;
    }
    while (last->next != NULL)
    {
        id++;
        last = last->next;
    }
    id = last->data.productID;
    id++;
    return id;

}
void ProductFunctions::declareData() {
    //Data Structure Initialization
    Product prod1, prod2,prod3,prod4,prod5,prod6;
    prod1 = {2, "Desk \"Modern\"", 1230}; append(prod1);
    prod2 = {3, "Kitchen chair", 370}; append(prod2);
    prod3 = {4, "Sofa \"Modern\"", 960}; append(prod3);
    prod4 = {5, "Kitchen chair", 370}; append(prod4);
    prod5 = {6, "Gaming chair", 450}; append(prod5);
    prod6 = {7, "Study table", 760}; append(prod6);

}

struct ProductNode* middle(ProductNode* start, ProductNode* last)
{
    if (start == NULL)
        return NULL;

    struct ProductNode* slow = start;
    struct ProductNode* fast = start -> next;

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

bool ProductFunctions::checkId(int id,  Product *product) { //BINARY SEARCH FOR FASTER ACCESS

    struct ProductNode* start = producthead;
    struct ProductNode* last = NULL;
    do
    {
        // Find middle
        ProductNode* mid = middle(start, last);

        // If middle is empty
        if (mid == NULL)
            return false;

        // If value is present at middle
        if (mid -> data.productID == id){
            *product = mid->data;
            return true;}

            // If value is more than mid
        else if (mid -> data.productID < id)
            start = mid -> next;

            // If the value is less than mid.
        else
            last = mid;

    } while (last == NULL ||
             last != start);

    // value not present
    return false;
}

void ProductFunctions::getProductData(int *id, string *name, int *price) {
    struct ProductNode* first = producthead;
    struct ProductNode* last = NULL;
    do
    {
        // Find middle
        ProductNode* mid = middle(first, last);
        // If middle is empty
        if (mid == NULL)
            return ;
        // If value is present at middle
        if (mid -> data.productID == *id ){
            *name = mid -> data.productName;
            *price = mid -> data.price;
            return ;
        }
            // If value is more than mid
        else if (mid -> data.productID < *id)
            first = mid -> next;
            // If the value is less than mid.
        else
            last = mid;
    } while (last == NULL ||
             last != first);
    // value not present
    return ;
}


