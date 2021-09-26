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


/*Guaranteed to not be first or last node in LL*/
void deleteMiddleNode(LinkedListNode *node) {
    if (node == NULL) {
        return;
    }
    node->setData(node->getNext()->getData());
    node->setNext(node->getNext()->getNext());
}

int main() {
    LinkedListNode n1(1);
    LinkedListNode n2(2);
    LinkedListNode n3(3);
    LinkedListNode n4(4);
    LinkedListNode n5(5);
    LinkedListNode n6(6);

    n1.setNext(&n2);
    n2.setNext(&n3);
    n3.setNext(&n4);
    n4.setNext(&n5);
    n5.setNext(&n6);
    
    printList(&n1);
    deleteMiddleNode(&n4);
    printList(&n1);
}
