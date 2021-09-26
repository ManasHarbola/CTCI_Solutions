#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> getPowerSet(vector<int> set) {
    vector<vector<int>> powerSet = {{}};
    int currSz;

    for (int i = 0; i < set.size(); i++) {
        currSz = powerSet.size();
        for (int j = 0; j < currSz; j++) {
            vector<int> newSet(powerSet[j]);
            newSet.push_back(set[i]);
            powerSet.push_back(newSet);
        }
    }

    return powerSet;
}

void printPowerSet(vector<vector<int>> ps) {
    cout << "{";
    for (auto s : ps) {
        cout << "{";
        for (int i = 0; i < s.size(); i++) {
            cout << s[i];
            if (i != s.size() - 1)
                cout << ", ";
        }
        cout << "}, ";
    }
    cout << "}" << endl;
}

int main() {
    vector<int> set = {1, 2, 3, 4, 5};

    printPowerSet(getPowerSet(set));
}
