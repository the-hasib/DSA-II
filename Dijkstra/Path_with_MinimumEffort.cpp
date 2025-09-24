#include <iostream>
#include <climits>
using namespace std;

const int MAX = 100;
const int INF = INT_MAX;

int effort[MAX][MAX];
int parentRow[MAX][MAX];
int parentCol[MAX][MAX];

int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

// Initialize effort matrix and parents
void initEffort(int m, int n) {
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            effort[i][j] = INF;
            parentRow[i][j] = -1;
            parentCol[i][j] = -1;
        }
    }
}

// Helper function to print path recursively
void printPath(int r, int c) {
    if(parentRow[r][c] == -1 && parentCol[r][c] == -1){
        cout << "(" << r << "," << c << ") ";
        return;
    }
    printPath(parentRow[r][c], parentCol[r][c]);
    cout << "-> (" << r << "," << c << ") ";
}

void dijkstra(int grid[MAX][MAX], int m, int n) {
    initEffort(m, n);
    
    // Start cell effort 0
    effort[0][0] = 0;
    bool visited[MAX][MAX] = {false};

    for (int count = 0; count < m * n; count++) {
        int uRow = -1, uCol = -1, minEff = INF;
        // Find node with minimum effort not visited yet
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(!visited[i][j] && effort[i][j] < minEff){
                    minEff = effort[i][j];
                    uRow = i;
                    uCol = j;
                }
            }
        }

        if(uRow == -1 && uCol == -1) break; // No unvisited nodes
        visited[uRow][uCol] = true;

        // Relax neighbors
        for(int d=0; d<4; d++) {
            int r = uRow + dir[d][0];
            int c = uCol + dir[d][1];
            if(r>=0 && r<m && c>=0 && c<n){
                int diff = abs(grid[uRow][uCol] - grid[r][c]);
                int maxEff = max(effort[uRow][uCol], diff);
                if(maxEff < effort[r][c]){
                    effort[r][c] = maxEff;
                    parentRow[r][c] = uRow;
                    parentCol[r][c] = uCol;
                }
            }
        }
    }
}

int main() {
    int m = 3, n = 3;
    int heights[MAX][MAX] = { {1,2,2}, {3,8,2}, {5,3,5} };

    dijkstra(heights, m, n);
    cout << "Minimum effort: " << effort[m-1][n-1] << endl;

    cout << "Path: ";
    printPath(m-1, n-1);
    cout << endl;

    return 0;
}
