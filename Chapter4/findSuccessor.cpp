#include <iostream>
using namespace std;

class Node {
    private:
        int _val;
        Node *_parent, *_left, *_right;
    public:
        Node(int val=0) {
            _val = val;
            _left = NULL;
            _right = NULL;
            _parent = NULL;
        }
        Node (int val, Node *parent, Node *left, Node *right) {
            _val = val;
            _parent = parent;
            _left = left;
            _right = right;
        }
        
        void setVal(int val) {_val = val;}
        void setParent(Node *parent) {_parent = parent;}
        void setLeft(Node *left) {_left = left;}
        void setRight(Node *right) {_right = right;}

        int getVal() {return _val;}
        Node *getParent() {return _parent;}
        Node *getLeft() {return _left;}
        Node *getRight() {return _right;}
};

Node *getSuccessor(Node *root) {
    Node *successor = NULL;
    if (root == NULL) {
        return successor;
    }

    //check if root has right child, else traverse up to see parent
    if (root->getRight() != NULL) {
        successor = root->getRight();
        //keep going down left off right child to get successor
        while (successor->getLeft() != NULL) {
            successor = successor->getLeft();
        }
        return successor;
    } else {
        //keep going up to parent until parent is greater than child it originated from
        Node *child = root;
        Node *parent = root->getParent();
        while (parent != NULL && parent->getVal() < child->getVal()) {
            child = parent;
            parent = parent->getParent();
        }
        return parent;
    }
    
}

int main() {
    return 0;
}
