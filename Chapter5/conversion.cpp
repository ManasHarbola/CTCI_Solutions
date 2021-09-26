#include <iostream>
using namespace std;

int conversion(int a, int b) {
    int n = a ^ b;
    int count = 0;
    while (n > 0) {
        count++;
        n = n & (n - 1);
    }
    return count;
}

int main() {
    cout << conversion(29, 15) << endl;
}
