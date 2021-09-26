#include <iostream>
using namespace std;

bool isOneEditAway(string s1, string s2) {
    int diff = s1.size() - s2.size();
    if (diff < -1 || diff > 1) {
        return false;
    }
    string *smaller, *larger;
    if (diff < 0) {
        smaller = &s1;
        larger = &s2;
    } else {
        smaller = &s2;
        larger = &s1;
    }
    bool mismatchFound = false;
    for (int i = 0, j = 0; i < smaller->size() && j < larger->size(); i++, j++) {
        if (smaller->at(i) != larger->at(j)) {
            if (mismatchFound) {
                return false;
            }
            mismatchFound = true;
            if (diff == 1 || diff == -1) {
                i--;
            }
        }
    }
    return true;
}

int main() {
    cout << isOneEditAway("pale", "ple") << endl;
    cout << isOneEditAway("pales", "pale") << endl;
    cout << isOneEditAway("bale", "pale") << endl;
    cout << isOneEditAway("pale", "bake") << endl;

}
