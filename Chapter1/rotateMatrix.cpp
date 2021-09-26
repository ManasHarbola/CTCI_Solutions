#include <iostream>
#include <vector>

using namespace std;

void swap(int &x, int &y) {
    int t = x;
    x = y;
    y = t;
}

void rotateMatrix(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int layers = n / 2;
    int leftRow = 0, leftCol = 0;
    int numRotations = n - 1;
    for (int i = 0; i < layers; i++) {
        int r1 = leftRow, c1 = leftCol;
        int r2 = leftRow, c2 = leftCol + numRotations;
        int r3 = leftRow + numRotations, c3 = leftCol;
        int r4 = leftRow + numRotations, c4 = leftCol + numRotations;
        for (int j = 0; j < numRotations; j++) {
            swap(matrix[r1][c1], matrix[r3][c3]);
            swap(matrix[r3][c3], matrix[r4][c4]);
            swap(matrix[r4][c4], matrix[r2][c2]);
            r1++;
            c2--;
            c3++;
            r4--;
        }
        leftRow++;
        leftCol++;
        numRotations -= 2;
    }
}

void printMatrix(vector<vector<int>> &matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    vector<vector<int>> one = {{1}};
    printMatrix(one, 1, 1);
    rotateMatrix(one);
    printMatrix(one, 1, 1);

    vector<vector<int>> x22 = {{1, 2},
                                    {3, 4}};
    printMatrix(x22, 2, 2);
    rotateMatrix(x22);
    printMatrix(x22, 2, 2);

    vector<vector<int>> x33 = {{1, 2, 3},
                              {4, 5, 6},
                              {7, 8, 9}};
    printMatrix(x33, 3, 3);
    rotateMatrix(x33);
    printMatrix(x33, 3, 3);

    vector<vector<int>> x44 = {{1,  2, 3, 4},
                               {5,  6, 7, 8},
                               {9,  10, 11, 12},
                               {13, 14, 15, 16}};
    printMatrix(x44, 4, 4);
    rotateMatrix(x44);
    printMatrix(x44, 4, 4);


    vector<vector<int>> x55 = {{1, 2, 3, 4, 5},
                               {6, 7, 8, 9, 10},
                               {11, 12, 13, 14, 15},
                               {16, 17, 18, 19, 20},
                               {21, 22, 23, 24, 25}};
    printMatrix(x55, 5, 5);
    rotateMatrix(x55);
    printMatrix(x55, 5, 5);
    return 0;
}
