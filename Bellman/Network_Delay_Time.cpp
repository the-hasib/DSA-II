#include <iostream>
#include <climits>
using namespace std;

const int MAX = 110; // Problem constraint n ≤ 100
const int INF = INT_MAX;

struct Edge {
    int u, v, w;
};

Edge edges[MAX * MAX];
int edgeCount = 0;

void addEdge(int u, int v, int w) {
    edges[edgeCount].u = u;
    edges[edgeCount].v = v;
    edges[edgeCount].w = w;
    edgeCount++;
}

int networkDelayBellmanFord(int n, int k) {
    int dist[MAX];
    for (int i = 1; i <= n; i++) dist[i] = INF;
    dist[k] = 0; // source node

    // Relax edges (n-1) times
    for (int t = 1; t <= n - 1; t++) {
        for (int i = 0; i < edgeCount; i++) {
            int u = edges[i].u, v = edges[i].v, w = edges[i].w;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    // Find maximum delay to reach all nodes
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) return -1;
        if (dist[i] > ans) ans = dist[i];
    }
    return ans;
}

int main() {
    int n = 4;
    edgeCount = 0;

    // times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2 (1-based input as in the example)
    addEdge(2, 1, 1);
    addEdge(2, 3, 1);
    addEdge(3, 4, 1);

    int k = 2;
    int delay = networkDelayBellmanFord(n, k);

    cout << "Minimum network delay time: " << delay << endl; // Output: 2

    return 0;
}
