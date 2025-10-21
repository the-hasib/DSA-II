class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Step 1: Create distance matrix
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        
        // Step 2: Distance to itself = 0
        for (int i = 0; i < n; i++) dist[i][i] = 0;

        // Step 3: Fill given edges (undirected)
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }

        // Step 4: Floyd–Warshall (find all-pairs shortest path)
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        // Step 5: Count reachable cities for each city
        int ansCity = -1;
        int minReach = 1e9;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && dist[i][j] <= distanceThreshold)
                    cnt++;
            }

            // smallest number of reachable cities, but largest index in tie
            if (cnt <= minReach) {
                minReach = cnt;
                ansCity = i;
            }
        }

        return ansCity;
    }
};
