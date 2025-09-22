#include <iostream>
#include <climits> // for INT_MAX

using namespace std;

const int MAX = 100;      // Maximum number of vertices
const int INF = INT_MAX;  // Represents infinity (initial distances)

int graph[MAX][MAX];  // Adjacency matrix to store edge weights
int parent[MAX];      // To store the parent of each vertex in shortest path

// Initialize the graph with zero distance for self loops and INF for others
void initGraph(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                graph[i][j] = 0;     // Distance to itself is zero
            else
                graph[i][j] = INF;   // No edge initially
        }
    }
}

// Add an edge between vertices u and v with weight w (undirected graph)
void addEdge(int u, int v, int w) {
    graph[u][v] = w;
    graph[v][u] = w;
}

// Find the vertex with minimum distance value from the set of vertices not yet processed
int minDistance(int dist[], bool visited[], int n) {
    int minVal = INF;
    int minIndex = -1;
    for (int v = 0; v < n; v++) {
        if (!visited[v] && dist[v] < minVal) {
            minVal = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Dijkstra's algorithm to find shortest path from source to all vertices
void dijkstra(int src, int n) {
    int dist[MAX];       // Initialize distances from source to all vertices
    bool visited[MAX];   // Track vertices for which shortest path is finalized

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = false;
        parent[i] = -1; // No parent initially
    }
    dist[src] = 0;  // Distance from source to itself is zero

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n); // Pick vertex with minimum dist
        if (u == -1)
            break;  // All reachable vertices processed
        visited[u] = true;

        // Update dist value of adjacent vertices of the picked vertex
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != INF && dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u; // Update parent for path reconstruction
            }
        }
    }

    // Print the shortest distances
    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "To vertex " << i << " : ";
        if (dist[i] == INF)
            cout << "No path\n";
        else
            cout << dist[i] << "\n";
    }
}

// Recursive function to print shortest path from source to destination
void printPath(int dest) {
    if (parent[dest] == -1) {
        cout << dest << " ";
        return;
    }
    printPath(parent[dest]);
    cout << dest << " ";
}

int main() {
    int n = 5;  // Number of vertices
    initGraph(n);

    // Add edges to the graph
    addEdge(0, 1, 10);
    addEdge(0, 4, 5);
    addEdge(1, 2, 1);
    addEdge(1, 4, 2);
    addEdge(2, 3, 4);
    addEdge(3, 0, 7);
    addEdge(3, 2, 6);
    addEdge(4, 2, 9);
    addEdge(4, 3, 2);

    int src = 0;  // Source vertex
    dijkstra(src, n);

    int dest = 3;  // Destination vertex
    cout << "Path from " << src << " to " << dest << ": ";
    printPath(dest);
    cout << "\n";

    return 0;
}
