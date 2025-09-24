#include <iostream>
#include <climits>
using namespace std;

const int MAX = 110;
const int INF = INT_MAX;
int graph[MAX][MAX];

void initGraph(int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = (i == j) ? 0 : INF;
}

void addEdge(int u, int v, int w) {
    graph[u][v] = w; // Directed
}

int networkDelay(int n, int k) {
    int dist[MAX];
    bool visited[MAX];
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = false;
    }
    dist[k] = 0; // node numbers are 1-based (as per LC)
    for (int count = 0; count < n; count++) {
        int u = -1, minVal = INF;
        for (int v = 1; v <= n; v++) {
            if (!visited[v] && dist[v] < minVal) {
                minVal = dist[v];
                u = v;
            }
        }
        if (u == -1) break;
        visited[u] = true;
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] != INF && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    int maxTime = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) return -1;
        if (dist[i] > maxTime) maxTime = dist[i];
    }
    return maxTime;
}

int main() {
    int n = 4; // number of nodes
    initGraph(n + 1);
    // times = [[2,1,1],[2,3,1],[3,4,1]]
    addEdge(2, 1, 1);
    addEdge(2, 3, 1);
    addEdge(3, 4, 1);

    int k = 2; // source node
    int ans = networkDelay(n, k);

    cout << "Network delay: " << ans << endl;
    return 0;
}
