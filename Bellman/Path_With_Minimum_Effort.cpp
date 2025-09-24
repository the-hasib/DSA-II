#include <iostream>
#include <climits>
#include <vector>
#include <cmath>
using namespace std;

const int MAX = 10000; // Sufficiently large for grid max nodenum
const int INF = INT_MAX;

struct Edge {
    int u, v, w;
};

Edge edges[MAX];
int parent[MAX];
int edgeCount = 0;

// Calculate node id from grid coordinates
int nodeID(int r, int c, int n) {
    return r * n + c;
}

// Add edge with cost (effort) between nodes u & v (bidirectional)
void addEdge(int u, int v, int w) {
    edges[edgeCount].u = u;
    edges[edgeCount].v = v;
    edges[edgeCount].w = w;
    edgeCount++;
}

// Bellman-Ford algorithm adapted to minimum maximum effort
int bellmanFord(int n, int src) {
    int dist[MAX];
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[src] = 0;

    // Relax edges (n-1) times
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < edgeCount; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if (dist[u] != INF && max(dist[u], w) < dist[v]) {
                dist[v] = max(dist[u], w);
                parent[v] = u;
            }
        }
    }
    return dist[n-1];
}

int main() {
    int m = 3, n = 3;
    int heights[3][3] = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}
    };

    // Build graph edges from grid
    edgeCount = 0;
    for (int r = 0; r < m; r++){
        for (int c = 0; c < n; c++){
            int u = nodeID(r, c, n);
            // right neighbor
            if (c + 1 < n) {
                int v = nodeID(r, c+1, n);
                int w = abs(heights[r][c] - heights[r][c+1]);
                addEdge(u, v, w);
                addEdge(v, u, w); // bidirectional
            }
            // down neighbor
            if (r + 1 < m) {
                int v = nodeID(r+1, c, n);
                int w = abs(heights[r][c] - heights[r+1][c]);
                addEdge(u, v, w);
                addEdge(v, u, w); // bidirectional
            }
        }
    }

    int totalNodes = m * n;
    int src = 0;       // top-left
    int effort = bellmanFord(totalNodes, src);

    cout << "Minimum effort to reach bottom-right: " << effort << endl;
    return 0;
}
