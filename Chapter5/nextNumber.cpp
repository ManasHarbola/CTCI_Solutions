#include <iostream>
using namespace std;

void nextNumbers(int num) {
    if (num == 0 || num == (~0)) {
        return;
    }
    bool foundSmall = false;
    bool foundLarge = false;
    for (int i = 0; i < 32 && !(foundSmall && foundLarge); i++) {
        int mask = 1 << i;
        if (num & mask) {
            if (i != 0 && !(num & (mask >> 1))) {
                cout << "next smallest " << (num ^ mask ^ (mask >> 1)) << endl;
                foundSmall = true;
            }
        } else {
            if (i != 0 && (num & (mask >> 1))) {
                cout << "next largest " << (num ^ mask ^ (mask >> 1)) << endl;
                foundLarge = true;
            }
        }

    }
}

int main() {
    nextNumbers(10);
    nextNumbers(9);
    nextNumbers(13948);
}
