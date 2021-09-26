#include <iostream>
#include <vector>
using namespace std;

class Node {
private:
    int value;
    Node *left;
    Node *right;
public:
    Node(int _value=0) {
        value = _value;
        left = NULL;
        right = NULL;
    }
    Node(int _value, Node *_left, Node *_right) {
        value = _value;
        left = _left;
        right = _right;
    }
    void setVal(int _value) {value = _value;}
    void setLeft(Node *_left) {left = _left;}
    void setRight(Node *_right) {right = _right;}

    int getVal() {return value;}
    Node *getRight() {return right;}
    Node *getLeft() {return left;}
};

Node *createHelper(vector<int> &nums, int l, int r) {
    //base case: leaf node
    if (l == r) {
        Node *n = new Node(nums[l]);
        return n;
    }
    int mid = l + ((r - l) / 2);
    Node *n = new Node(nums[mid]);
    if (mid - 1 >= l) {
        n->setLeft(createHelper(nums, l, mid - 1));
    }
    if (mid + 1 <= r) {
        n->setRight(createHelper(nums, mid + 1, r));
    }
    
    return n;
}

Node *createMinimalTree(vector<int> &nums) {
    if (nums.size() == 0) {
        return NULL;
    }
    return createHelper(nums, 0, nums.size() - 1);
}


void preOrder(Node *root) {
    if (root == NULL) {
        cout << " NULL ";
        return;
    }
    cout << " " << root->getVal() << " ";
    preOrder(root->getLeft());
    preOrder(root->getRight());
}

int main() {
    int numTests = 11;
    for (int i = 1; i < numTests; i++) {
        vector<int> tmp;
        for (int j = 0; j < i; j++) {
            tmp.push_back(j);
        }
        Node *head = createMinimalTree(tmp);
        preOrder(head);
        cout << "\n";
    }
}
