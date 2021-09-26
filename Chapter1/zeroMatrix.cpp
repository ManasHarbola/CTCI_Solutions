#include <iostream>
#include <vector>
using namespace std;

void printMatrix(vector<vector<int>> &matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void zeroRow(vector<vector<int>> &matrix, int r) {
    for (int i = 0; i < matrix[r].size(); i++) {
        matrix[r][i] = 0;
    }
}

void zeroCol(vector<vector<int>> &matrix, int c) {
    for (int i = 0; i < matrix.size(); i++) {
        matrix[i][c] = 0;
    }
}

void zeroMatrix(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    
    bool firstRowHasZero = false;
    bool firstColHasZero = false;

    for (int i = 0; i < n; i++) {
        if (matrix[0][i] == 0) {
            firstRowHasZero = true;
            break;
        }
    }
    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == 0) {
            firstColHasZero = true;
            break;
        }
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (matrix[0][i] == 0) {
            zeroCol(matrix, i);
        }
    }
    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == 0) {
            zeroRow(matrix, i);
        }
    }
    if (firstRowHasZero) {
        zeroRow(matrix, 0);
    }
    if (firstColHasZero) {
        zeroCol(matrix, 0);
    }
}

int main() {
    return 0;
}
