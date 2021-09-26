#include <iostream>
using namespace std;

void urlify(char *arr, size_t n) {
    if (n == 0) {
        return;
    }
    int numSpaces = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] == ' ') {
            numSpaces++;
        }
    }

    size_t urlSize = n + 2*numSpaces;
    int currIdx = urlSize - 1;

    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] == ' ') {
            arr[currIdx - 2] = '%';
            arr[currIdx - 1] = '2';
            arr[currIdx] = '0';
            currIdx -= 3;
        } else {
            arr[currIdx] = arr[i];
            currIdx--;
        }
    }
}

int main() {
    char arr[] = "Mr John Smith    ";
    urlify((char *)(&arr), 13);
    cout << "\'" << arr << "\'" << endl;
}
