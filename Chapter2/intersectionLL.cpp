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

LinkedListNode *intersectionLL(LinkedListNode *l1, LinkedListNode *l2) {
    if (l1 == NULL || l2 == NULL) {
        return NULL;
    }

    LinkedListNode *head1 = l1;
    LinkedListNode *head2 = l2;
    int length1 = 1, length2 = 1;

    while (head1->getNext() != NULL) {
        length1++;
        head1 = head1->getNext();
    }
    while (head2->getNext() != NULL) {
        length2++;
        head2 = head2->getNext();
    }
    if (head1 != head2) {
        return NULL;
    }
    head1 = l1;
    head2 = l2;
    if (length1 > length2) {
        while (length1 > length2) {
            head1 = head1->getNext();
            length1--;
        }
    } else if (length2 > length1) {
        while (length2 > length1) {
            head2 = head2->getNext();
            length2--;
        }
    }
    while (head1 != head2) {
        head1 = head1->getNext();
        head2 = head2->getNext();
    }
    return head1;
}

int main() {
    LinkedListNode n1(3);
    LinkedListNode n2(1);
    LinkedListNode n3(5);
    LinkedListNode n4(9);

    LinkedListNode n5(4);
    LinkedListNode n6(6);

    LinkedListNode n7(7);
    LinkedListNode n8(2);
    LinkedListNode n9(1);

    n1.setNext(&n2);
    n2.setNext(&n3);
    n3.setNext(&n4);
    n4.setNext(&n7);

    n5.setNext(&n6);
    n6.setNext(&n7);
    n7.setNext(&n8);
    n8.setNext(&n9);
    
    printList(&n1);
    printList(&n5);

    cout << intersectionLL(&n1, &n5)->getData() << endl;
}
