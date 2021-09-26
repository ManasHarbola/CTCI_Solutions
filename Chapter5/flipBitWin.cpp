#include <iostream>
using namespace std;

int flipBitWin(int num) {
    int largest = 0;
    int prevCount = 0;
    int currCount = 0;
    bool seenZero = false;
    while (num != 0) {
        if (num & 1) {
            currCount++;
        } else {
            if (seenZero) {
                largest = max(largest, currCount);
                prevCount = currCount;
                currCount = 0;
                seenZero = false;
            } else {
                seenZero = true;
            }
        }
        num >>= 1;
    }
    return max(largest, currCount) + 1;
}

int main() {
    cout << flipBitWin(517103);
}
