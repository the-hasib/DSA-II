#include <iostream>
using namespace std;

const int MAX = 100;

double graph[MAX][MAX];
double prob[MAX];
bool visited[MAX];
int parent[MAX];

// Initialize, all probabilities 0 except diagonal
void initGraph(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            graph[i][j] = (i == j) ? 1.0 : 0.0;
    }
}

// Add undirected probability edge
void addEdge(int u, int v, double p) {
    graph[u][v] = p;
    graph[v][u] = p;
}

// Find unvisited node with current highest probability
int maxProbNode(int n) {
    double maxVal = 0.0;
    int maxIdx = -1;
    for (int v = 0; v < n; v++) {
        if (!visited[v] && prob[v] > maxVal) {
            maxVal = prob[v];
            maxIdx = v;
        }
    }
    return maxIdx;
}

// Dijkstra style: maximize product of probabilities rather than minimize sum
void maxProbability(int src, int n) {
    for (int i = 0; i < n; i++) {
        prob[i] = 0.0;
        visited[i] = false;
        parent[i] = -1;
    }
    prob[src] = 1.0;

    for (int cnt = 0; cnt < n; cnt++) {
        int u = maxProbNode(n);
        if (u == -1) break;
        visited[u] = true;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] > 0.0) {
                // Replace with max probability
                if (prob[u] * graph[u][v] > prob[v]) {
                    prob[v] = prob[u] * graph[u][v];
                    parent[v] = u;
                }
            }
        }
    }
}

int main() {
    int n = 3;
    initGraph(n);
    // Problem sample: edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start=0, end=2
    addEdge(0, 1, 0.5);
    addEdge(1, 2, 0.5);
    addEdge(0, 2, 0.2);

    int start = 0, end = 2;
    maxProbability(start, n);

    cout << "Maximum probability from " << start << " to " << end << ": ";
    cout << prob[end] << endl; // Output: 0.25 expected

    return 0;
}
