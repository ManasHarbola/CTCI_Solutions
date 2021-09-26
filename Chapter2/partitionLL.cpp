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

LinkedListNode *partitionLL(LinkedListNode *head, int pivot) {
    if (head == NULL) {
        return NULL;
    }
    if (head->getNext() == NULL) {
        return head;
    }
    
    LinkedListNode *leftPartitionHead = NULL;
    LinkedListNode *leftPartitionTail = NULL;
    LinkedListNode *rightPartitionHead = NULL;
    LinkedListNode *currNode;

    while (head != NULL) {
        currNode = head;
        head = head->getNext();
        if (currNode->getData() < pivot) {
            if (leftPartitionTail == NULL) {
                leftPartitionTail = currNode;
            }
            currNode->setNext(leftPartitionHead);
            leftPartitionHead = currNode;
        } else {
            currNode->setNext(rightPartitionHead);
            rightPartitionHead = currNode;
        }
    } 

    if (leftPartitionHead == NULL) {
        return rightPartitionHead;
    }
    leftPartitionTail->setNext(rightPartitionHead);
    return leftPartitionHead;
}

int main() {
    LinkedListNode n1(3);
    LinkedListNode n2(5);
    LinkedListNode n3(8);
    LinkedListNode n4(5);
    LinkedListNode n5(10);
    LinkedListNode n6(2);
    LinkedListNode n7(1);

    n1.setNext(&n2);
    n2.setNext(&n3);
    n3.setNext(&n4);
    n4.setNext(&n5);
    n5.setNext(&n6);
    n6.setNext(&n7);
    
    printList(&n1);
    printList(partitionLL(&n1, 5));
}
