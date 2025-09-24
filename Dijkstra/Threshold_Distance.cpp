#include <iostream>
#include <climits>
using namespace std;

const int MAX = 100;
const int INF = INT_MAX;

int graph[MAX][MAX];
int parent[MAX];


void initGraph(int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = (i == j) ? 0 : INF;
}

void addEdge(int u, int v, int w) {
    graph[u][v] = w;
    graph[v][u] = w;
}

int minDistance(int dist[], bool visited[], int n) {
    int minVal = INF, minIndex = -1;
    for (int v = 0; v < n; v++) {
        if (!visited[v] && dist[v] < minVal) {
            minVal = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void dijkstra(int src, int n, int dist[]) {
    bool visited[MAX];
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }
    dist[src] = 0;
    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        if (u == -1) break;
        visited[u] = true;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != INF && dist[u] != INF
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
}


int findCity(int n, int distanceThreshold) {
    int answer = -1, minCount = n + 1;
    int dist[MAX];
    for (int city = 0; city < n; city++) {
        dijkstra(city, n, dist);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (i != city && dist[i] <= distanceThreshold) {
                count++;
            }
        }
        if (count <= minCount) {
            minCount = count;
            answer = city;
        }
    }
    return answer;
}

int main() {
    int n = 5;
    initGraph(n);
    addEdge(0, 1, 2);
    addEdge(1, 4, 8);
    addEdge(1, 2 , 3);
    addEdge(1, 4, 2);
    addEdge(2, 3, 1);
    addEdge(3, 4, 1);

    int distanceThreshold = 2;

    int city = findCity(n, distanceThreshold);
    cout << city << endl; 

    return 0;
}
