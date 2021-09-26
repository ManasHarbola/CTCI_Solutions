#include <iostream>
using namespace std;

class LinkedListNode {
    private:
        int data;
        LinkedListNode *next;
    public:
        LinkedListNode(int val, LinkedListNode *nextNode=NULL) {
            data = val;
            next = nextNode;
        }
        int getData() {return data;}
        LinkedListNode *getNext() {return next;}
        void setData(int val) {
            data = val;
        }
        void setNext(LinkedListNode *nextNode) {
            next = nextNode;
        }
};

void printList(LinkedListNode *node) {
    if (node == NULL) {
        cout << "null" << endl;
        return;
    }
    while (node != NULL) {
        cout << node->getData() << " -> ";
        node = node->getNext();
    }
    cout << "NULL" << endl << endl;
}

LinkedListNode *detectLoop(LinkedListNode *head) {
    if (head == NULL) {
        return NULL;
    }
    LinkedListNode *slowPtr = head;
    LinkedListNode *fastPtr = head->getNext();
    while (slowPtr != fastPtr && fastPtr != NULL) {
        slowPtr = slowPtr->getNext();
        fastPtr = fastPtr->getNext();
        if (fastPtr == NULL) {
            return NULL;
        }
        fastPtr = fastPtr->getNext();
    }
    return fastPtr;
}
