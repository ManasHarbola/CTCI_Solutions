#include <iostream>
#include <unordered_set>
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
        void setNext(LinkedListNode *nextNode) {
            next = nextNode;
        }
};

void removeDups(LinkedListNode *node) {
    if (node == NULL) {
        return;
    }
    unordered_set<int> encountered;
    LinkedListNode *prev = NULL;
    while (node != NULL) {
        if (encountered.find(node->getData()) != encountered.end()) {
            prev->setNext(node->getNext());
        } else {
            encountered.insert(node->getData());
            prev = node;
        }
        node = node->getNext();
    }
}

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

int main() {
    LinkedListNode n1(1);
    LinkedListNode n2(2);
    LinkedListNode n3(1);
    LinkedListNode n4(1);
    LinkedListNode n5(3);
    LinkedListNode n6(3);

    n1.setNext(&n2);
    n2.setNext(&n3);
    n3.setNext(&n4);
    n4.setNext(&n5);
    n5.setNext(&n6);
    
    printList(&n1);
    removeDups(&n1);
    printList(&n1);
}


