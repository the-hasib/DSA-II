#include <iostream>
#include <climits>
using namespace std;

const int MAX = 100;
const int INF = INT_MAX;

struct Edge {
    int u, v, w;
};

Edge edges[MAX];
int parent[MAX];
int edgeCount = 0;

// Add edge to edges array
void addEdge(int u, int v, int w) {
    edges[edgeCount].u = u;
    edges[edgeCount].v = v;
    edges[edgeCount].w = w;
    edgeCount++;
}

void bellmanFord(int n, int src) {
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
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }

    // Check for negative-weight cycle
    for (int j = 0; j < edgeCount; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            cout << "Graph contains a negative-weight cycle" << endl;
            return;
        }
    }

    // Print results
    for (int i = 0; i < n; i++) {
        cout << "Distance to node " << i << ": ";
        if (dist[i] == INF) cout << "Not reachable" << endl;
        else cout << dist[i] << endl;
    }
}

// Recursive function to print path from source to dest
void printPath(int dest) {
    if (parent[dest] == -1) {
        cout << dest << " ";
        return;
    }
    printPath(parent[dest]);
    cout << dest << " ";
}

int main() {
    int n = 5;  // Number of nodes

    // Adding example edges with negative weight cycle possibility
    addEdge(0, 1, 6);
    addEdge(0, 2, 7);
    addEdge(1, 2, 8);
    addEdge(1, 3, 5);
    addEdge(1, 4, -4);
    addEdge(2, 3, -3);
    addEdge(2, 4, 9);
    addEdge(3, 1, -2);
    addEdge(4, 3, 7);
    addEdge(4, 0, 2);

    int src = 0;
    bellmanFord(n, src);

    // If no negative cycle, print paths
    for (int i = 0; i < n; i++) {
        cout << "Path to " << i << ": ";
        printPath(i);
        cout << endl;
    }
    return 0;
}
