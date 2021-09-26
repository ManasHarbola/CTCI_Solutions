#include <iostream>
#include <string>

using namespace std;

bool isStringRotation(string s1, string s2) {
    if (s1.size() != s2.size()) {
        return false;
    }
    if (s1.size() == 0) {
        return true;
    }
    string doubles1 = s1 + s1;
    return (doubles1.find(s2) != string::npos);
}

int main() {
    cout << isStringRotation("waterbottle", "erbottlewat") << endl;
}
