

#ifndef ORDERQUEUE_H
#define ORDERQUEUE_H
#include <iostream>
#include "../Orders/OrderNode.h"

using namespace std;

struct QNode {
    OrderNode* data; // here data is actual head of element in linked list
    QNode* next;
    QNode(OrderNode *d)
    {
        data = d;
        next = NULL;
    }
};
struct Queue {
    QNode *front, *rear;
    Queue()
    {
        front = rear = NULL;
    }

    void enQueue(OrderNode* head)
    {

        // Create a new LL node
        QNode* temp = new QNode(head);

        // If queue is empty, then
        // new node is front and rear both
        if (rear == NULL) {
            front = rear = temp;
            return;
        }

        // Add the new node at
        // the end of queue and change rear
        rear->next = temp;
        rear = temp;
    }

    // Function to remove
    // a key from given queue q
    void deQueue()
    {
        // If queue is empty, return NULL.
        if (front == NULL)
            return;

        // Store previous front and
        // move front one node ahead
        QNode* temp = front;
        front = front->next;

        // If front becomes NULL, then
        // change rear also as NULL
        if (front == NULL)
            rear = NULL;

        delete (temp);
    }
};



#endif //DSTR_ORDERQUEUE_H
