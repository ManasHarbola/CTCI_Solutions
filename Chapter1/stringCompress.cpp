#include <iostream>
#include <string>
using namespace std;

string compress(string s) {
    if (s.size() <= 1) {
        return s;
    }
    
    size_t compressedSz = 0;
    char prev = s[0];
    int currFreq = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != prev) {
            compressedSz += (1 + to_string(currFreq).size());
            prev = s[i];
            currFreq = 1;
        } else {
            currFreq++;
        }
        if (i == s.size() - 1) {
            compressedSz += (1 + to_string(currFreq).size());
        }
    }
    
    if (compressedSz >= s.size()) {
        return s;
    }

    string compressed(compressedSz, ' ');
    prev = s[0];
    currFreq = 1;
    int compressedIdx = 0;

    for (int i = 1; i < s.size(); i++) {
        if (s[i] != prev) {
            compressed[compressedIdx] = prev;
            string count = to_string(currFreq);
            for (int j = 0; j < count.size(); j++) {
                compressed[compressedIdx + 1 + j] = count[j];
            }
            prev = s[i];
            currFreq = 1;
            compressedIdx += (1 + count.size());
        } else {
            currFreq++;
        }
        if (i == s.size() - 1) {
            compressed[compressedIdx] = prev;
            string count = to_string(currFreq);
            for (int j = 0; j < count.size(); j++) {
                compressed[compressedIdx + 1 + j] = count[j];
            }
        }
    }
    return compressed;
}

int main() {
    cout << compress("aabcccccccccccccccccccccccccccccccccccccccccccccccaaa") << endl;
    cout << compress("aabbbcc") << endl;
    return 0;
}
