#include <iostream>
using namespace std;

int pairwiseSwp(int num) {
    int evenPart = num & 0xAAAAAAAA;
    int oddPart = num & 0x55555555;
    
    return ((evenPart >> 1) & (0x7FFFFFFF)) | (oddPart << 1);
}

int main() {
    cout << pairwiseSwp(-2147483648) << endl;
    cout << pairwiseSwp(10) << endl;
}
