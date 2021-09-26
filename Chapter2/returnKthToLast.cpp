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

void returnKthHelper(LinkedListNode *curr, int k, int &count, int &retVal) {
    if (curr == NULL) {
        count = -1;
        return;
    }
    returnKthHelper(curr->getNext(), k, count, retVal);
    count++;
    if (count == k) {
        retVal = curr->getData();
    }
}

int returnKthToLast(LinkedListNode *node, int k) {
    int value;
    int count = 0;
    returnKthHelper(node, k, count, value);
    return value;
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
    cout << returnKthToLast(&n1, 0) << endl;
    cout << returnKthToLast(&n1, 1) << endl;
    cout << returnKthToLast(&n1, 2) << endl;
    cout << returnKthToLast(&n1, 3) << endl;
    cout << returnKthToLast(&n1, 4) << endl;
    cout << returnKthToLast(&n1, 5) << endl;
}
