#include <iostream>
using namespace std;

//assumes i and j are in range 0-31, inclusive
int32_t insertion(int32_t n, int32_t m, int i, int j) {
    //clear bits i to j in n
    int32_t mask = (1 << (j - i + 1)) - 1;
    mask = ~(mask << i);
    m = m << i;
    n = (n & mask) | m;
    return n;
}

int main() {
    cout << insertion(1024, 19, 2, 6);
}
