#include <iostream>
using namespace std;

bool isPalindromePerm(string s) {
    int isOddCount[128] = {0};
    int numOddCount = 0;

    for (int i = 0; i < s.size(); i++) {
        isOddCount[s[i]]++;
        if (isOddCount[s[i]] % 2 == 1) {
            numOddCount++;
        } else {
            numOddCount--;
        }
    }
    return numOddCount < 2;
}

int main() {
    cout << isPalindromePerm("tactcoa");
    return 0;
}
