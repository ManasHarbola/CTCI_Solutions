#include <iostream>
using namespace std;

class Node {
    private:
        int _val;
        Node *_left, *_right;
    public:
        Node(int val=0) {
            _val = val;
            _left = NULL;
            _right = NULL;
        }
        Node (int val, Node *left, Node *right) {
            _val = val;
            _left = left;
            _right = right;
        }
        
        void setVal(int val) {_val = val;}
        void setLeft(Node *left) {_left = left;}
        void setRight(Node *right) {_right = right;}

        int getVal() {return _val;}
        Node *getLeft() {return _left;}
        Node *getRight() {return _right;}
};

struct Result {
    Node *ancestor;
    bool isAncestor;
};

Result fcaHelper(Node *curr, Node *n1, Node *n2) {
    Result r = {NULL, false};
    if (curr == NULL) {
        return r;
    }
    if (curr == n1 && curr == n2) {
        r.ancestor = n1;
        r.isAncestor = true;
        return r;
    }

    Result leftRes = fcaHelper(curr->getLeft(), n1, n2);
    if (leftRes.isAncestor) {
        return leftRes;
    }
    Result rightRes = fcaHelper(curr->getRight(), n1, n2);
    if (rightRes.isAncestor) {
        return rightRes;
    }

    if (rightRes.ancestor != NULL && leftRes.ancestor != NULL) {
        r.ancestor = curr;
        r.isAncestor = true;
        return r;
    }
    
    //curr is either an ancestor or just one of the nodes
    if (curr == n1 || curr == n2) {
        r.ancestor = curr;
        r.isAncestor = leftRes.ancestor != NULL || rightRes.ancestor != NULL;
        return r;
    }
    
    //curr has a subtree which does/does not contain one of the two nodes
    return leftRes.ancestor != NULL ? leftRes : rightRes;
}

Node *firstCommonAncestor(Node *root, Node *n1, Node *n2) {
    Result r = fcaHelper(root, n1, n2);
    if (r.isAncestor) {
        return r.ancestor;
    }
    return NULL;
}



int main() {
    Node n1(3);
    Node n2(1);
    Node n3(5);
    Node n4(8);
    n1.setLeft(&n2);
    n1.setRight(&n3);
    n3.setRight(&n4);

    Node *root = &n1;
    cout << firstCommonAncestor(root, &n1, &n4)->getVal();
    return 0;
}
