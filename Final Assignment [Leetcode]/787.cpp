class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
         const int INF = 1e9; 
        vector<int> prev(n, INF), cur(n, INF);
        prev[src] = 0;

        for (int round = 0; round <= k; round++) {
           
            cur = prev;  
            for (auto &f : flights) {
                int u = f[0], v = f[1], w = f[2];
                if (prev[u] !=INF && prev[u] + w < cur[v]) {
                    cur[v] = prev[u] + w;
                }
            }
            prev = cur;
        }

        if (prev[dst] == INF) return -1;
        return prev[dst];
    }
};