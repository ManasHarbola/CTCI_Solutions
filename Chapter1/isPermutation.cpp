#include <iostream>
#include <algorithm>
using namespace std;

bool isPermutation(string s1, string s2) {
    if (s1.size() != s2.size()) {
        return false;
    }
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

bool isPermutation2(string s1, string s2) {
    if (s1.size() != s2.size()) {
        return false;
    }
    int freqTable[256] = {0};
    for (int i = 0; i < s1.size(); i++) {
        freqTable[s1[i]]++;
    }
    for (int i = 0; i < s2.size(); i++) {
        freqTable[s2[i]]--;
        if (freqTable[s2[i]] < 0) {
            return false;
        }
    }
    return true;
}


int main() {
    cout << isPermutation("abdc", "abcd") << endl;
    cout << isPermutation2("abdc", "abcd") << endl;

    return 0;

}
