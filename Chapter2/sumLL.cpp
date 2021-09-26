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

LinkedListNode *sumLL(LinkedListNode *l1, LinkedListNode *l2) {
    if (l1 == NULL || l2 == NULL) {
        return NULL;
    }

    int carryIn = 0;
    int sum = 0;
    LinkedListNode *head = NULL;
    LinkedListNode *tail = NULL;
    LinkedListNode *longer = NULL;

    while (l1 != NULL && l2 != NULL) {
        sum = l1->getData() + l2->getData() + carryIn;
        carryIn = sum / 10;
        sum %= 10;
        
        LinkedListNode *newNode = new LinkedListNode(sum);
        if (tail != NULL) {
            tail->setNext(newNode);
            tail = tail->getNext();
        } else {
            tail = newNode;
            head = tail;
        }

        l1 = l1->getNext();
        l2 = l2->getNext();
    }
    
    if (l1 != NULL) {
        longer = l1;
    } else if (l2 != NULL) {
        longer = l2;
    }
    while (longer != NULL) {
        sum = longer->getData() + carryIn;
        carryIn = sum / 10;
        sum %= 10;
        tail->setNext(new LinkedListNode(sum));
        tail = tail->getNext();
        longer = longer->getNext();
    }
    if (carryIn > 0) {
        tail->setNext(new LinkedListNode(carryIn));
    }
    return head;
}

int main() {
    LinkedListNode n1(9);
    LinkedListNode n2(9);
    LinkedListNode n3(9);

    LinkedListNode n4(1);
    LinkedListNode n5(9);
    LinkedListNode n6(9);

    n1.setNext(&n2);
    n2.setNext(&n3);
    
    n4.setNext(&n5);
    n5.setNext(&n6);
    
    printList(&n1);
    printList(&n4);

    printList(sumLL(&n1, &n4));
    return 0;
}
