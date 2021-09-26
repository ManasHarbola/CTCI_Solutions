#include <iostream>
#include <string>
#include <stack>

using namespace std;

//disk numbers are zero-indexed
void solveHanoi(int diskNum, stack<int> &src, stack<int> &dst, stack<int> &aux) {
    if (diskNum == 0) {
        dst.push(src.top());
        src.pop();
    } else {
        solveHanoi(diskNum - 1, src, aux, dst);
        dst.push(src.top());
        src.pop();
        solveHanoi(diskNum - 1, aux, dst, src);
    }
}

void printStack(string label, stack<int> &s) {
    stack<int> tmp;
    cout << label << " stack contents (top-to-bottom):\n";
    while (!s.empty()) {
        cout << s.top() << "\n";
        tmp.push(s.top());
        s.pop();
    }
    while (!tmp.empty()) {
        s.push(tmp.top());
        tmp.pop();
    }
}

int main() {
    stack<int> left, middle, right;
    
    int bottomRingNum = 4;
    for (int i = bottomRingNum; i >= 0; i--) {
        left.push(i);
    }
    printStack("left", left);
    printStack("middle", middle);
    printStack("right", right);

    solveHanoi(bottomRingNum, left, right, middle);

    cout << endl;

    printStack("left", left);
    printStack("middle", middle);
    printStack("right", right);
}
