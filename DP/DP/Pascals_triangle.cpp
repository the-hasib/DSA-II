#include <iostream>
using namespace std;

vector<vector<int>> buildPascalTriangle(int totalRows) {
    vector<vector<int>> pascalTriangle(totalRows);

    for (int currentRow = 0; currentRow < totalRows; currentRow++) {
        pascalTriangle[currentRow].resize(currentRow + 1);
        pascalTriangle[currentRow][0] = 1;
        pascalTriangle[currentRow][currentRow] = 1;

        for (int col = 1; col < currentRow; col++) {
            pascalTriangle[currentRow][col] =
                pascalTriangle[currentRow - 1][col - 1] +
                pascalTriangle[currentRow - 1][col];
        }
    }

    return pascalTriangle;
}

int main() {
    int totalRows;
    cout << "Enter number of rows: ";
    cin >> totalRows;

    vector<vector<int>> triangle = buildPascalTriangle(totalRows);

    cout << "\nPascal's Triangle (" << totalRows << " rows):\n";
    for (int row = 0; row < triangle.size(); row++) {
        for (int col = 0; col < triangle[row].size(); col++) {
            cout << triangle[row][col] << " ";
        }
        cout << endl;
    }

    return 0;
}
