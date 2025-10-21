class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Build graph
        vector<vector<pair<int, int>>> graph(n + 1);
        for (auto &t : times) {
            int u = t[0], v = t[1], w = t[2];
            graph[u].push_back({v, w});
        }

        // Distance array
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        // Min-heap (time, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();

            if (time > dist[node]) continue;

            for (auto &[next, weight] : graph[node]) {
                if (dist[node] + weight < dist[next]) {
                    dist[next] = dist[node] + weight;
                    pq.push({dist[next], next});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
