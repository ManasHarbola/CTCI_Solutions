#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isUnique(string s) {
    bool freqTable[256] = {false};
    for (int i = 0; i < s.size(); i++) {
        if (freqTable[s[i]]) {
            return false;
        } else {
            freqTable[s[i]] = true;
        }
    }
    return true;
}

bool isUnique2(string s) {
    for (int i = 0; i < s.size(); i++) {
        for (int j = i + 1; j < s.size(); j++) {
            if (s[i] == s[j]) {
                return false;
            }
        }
    }
    return true;
}

bool isUnique3(string s) {
    sort(s.begin(), s.end());
    for (int i = 0; i < ((int) s.size()) - 1; i++) {
        if (s[i] == s[i + 1]) {
            return false;
        }
    }
    return true;
}


int main() {
    cout << isUnique("dfghyqujti") << endl;
    cout << isUnique("acbda") << endl;
    cout << isUnique("") << endl;
    cout << isUnique("  ") << endl << endl;

    cout << isUnique2("dfghyqujti") << endl;
    cout << isUnique2("acbda") << endl;
    cout << isUnique2("") << endl;
    cout << isUnique2("  ") << endl << endl;

    cout << isUnique3("dfghyqujti") << endl;
    cout << isUnique3("acbda") << endl;
    cout << isUnique3("") << endl;
    cout << isUnique3("  ") << endl << endl;

    return 0;
}
