#include <iostream>
using namespace std;

int findMagicIndex(int arr[], size_t n) {
    int l = 0, r = n - 1;
    int mid;
    while (r >= l) {
        mid = l + ((r - l) / 2);
        if (arr[mid] == mid) {
            return mid;
        } else if (arr[mid] < mid) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {-99, -98, -97, -96, 3, 5, 7, 8, 9};
    int n = sizeof(arr)/sizeof(int);
    cout << findMagicIndex(arr, n) << endl;
}
