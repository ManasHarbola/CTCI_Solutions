#include <iostream>
using namespace std;

//top-down
int tripleStepHelper(int steps, int memo[]) {
    if (memo[steps] != -1) {
        return memo[steps];
    }
    memo[steps] = 0;
    if (steps - 1 >= 0) {
        memo[steps] += tripleStepHelper(steps - 1, memo);
    }
    if (steps - 2 >= 0) {
        memo[steps] += tripleStepHelper(steps - 2, memo);
    }
    if (steps - 3 >= 0) {
        memo[steps] += tripleStepHelper(steps - 3, memo);
    }
    return memo[steps];
}

int tripleStep(int steps) {
    int memo[steps + 1];
    for (int i = 0; i < steps + 1; i++) {
        memo[i] = -1;
    }
    memo[0] = 1;
    return tripleStepHelper(steps, memo);
}

//bottom-up
int tripleStep2(int steps) {
    int memo[steps + 1];
    memo[0] = 1;
    for (int i = 1; i < steps + 1; i++) {
        memo[i] = 0;
        if (i - 3 >= 0) {
            memo[i] += memo[i - 3];
        }
        if (i - 2 >= 0) {
            memo[i] += memo[i - 2];
        }
        if (i - 1 >= 0) {
            memo[i] += memo[i - 1];
        }
    }

    return memo[steps];
}

int main() {
    cout << tripleStep(15) << endl;
    cout << tripleStep2(15) << endl;
}
