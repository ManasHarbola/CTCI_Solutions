#include <iostream>
using namespace std;

int multiplyRec(int smaller, int larger) {
    if (smaller == 0) {
        return 0;
    }
    if (smaller == 1) {
        return larger;
    }

    int result = multiplyRec(smaller >> 1, larger) << 1;
    if (smaller & 1) {
        result += larger;
    }

    return result;
}

int multiply(int a, int b) {
    return a <= b ? multiplyRec(a, b) : multiplyRec(b, a);
}

int main() {
    cout << multiply(13, 5) << endl;
    cout << multiply(2048, 1025) << endl;
}
