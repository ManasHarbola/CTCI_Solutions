#include <iostream>
using namespace std;

string binaryToString(double num) {
    if (num == 0.0) {
        return "0.0";
    } else if (num == 1.0) {
        return "1.0";
    }

    string result(32, '0');
    result[1] = '.';

    int count = 2;
    double placeVal = 0.5;

    while (num != 0.0 && count < 32) {
        if (num >= placeVal) {
            result[count] = '1';
            num -= placeVal;
        }
        count++;
        placeVal /= 2;
    }
    if (num != 0.0) {
        return "error";
    }
    return result;
}

int main() {
    for (int i = 0 ; i < 1000; i++) {
        double n = i / 1000.0;
        string res = binaryToString(n);
        if (res != "error") {
            cout << res << endl;
        }
    }
}
