#include <iostream>
#include <climits>
using namespace std;

const int MAX = 110;
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

int bellmanFord(int n, int src, int dst, int K) {
    int cost[MAX];
    for (int i = 0; i < n; i++) cost[i] = INF;
    cost[src] = 0;

    // Bellman-Ford: Relax all edges K+1 times (K stops = K+1 flights)
    for (int step = 0; step <= K; step++) {
        int temp[MAX];
        for (int i = 0; i < n; i++) temp[i] = cost[i];
        for (int i = 0; i < edgeCount; i++) {
            int u = edges[i].u, v = edges[i].v, w = edges[i].w;
            if (cost[u] != INF && cost[u] + w < temp[v]) {
                temp[v] = cost[u] + w;
            }
        }
        for (int i = 0; i < n; i++) cost[i] = temp[i];
    }
    return (cost[dst] == INF) ? -1 : cost[dst];
}

int main() {
    int n = 4;
    edgeCount = 0;
    // flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]]
    addEdge(0, 1, 100);
    addEdge(1, 2, 100);
    addEdge(2, 0, 100);
    addEdge(1, 3, 600);
    addEdge(2, 3, 200);

    int src = 0, dst = 3, K = 1;
    int ans = bellmanFord(n, src, dst, K);

    cout << ans << endl; // Output: 700

    return 0;
}
