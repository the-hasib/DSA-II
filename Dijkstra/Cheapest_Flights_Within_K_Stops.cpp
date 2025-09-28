#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Node {
    int city, cost, stops;
    Node(int c, int co, int s) : city(c), cost(co), stops(s) {}
};

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    vector<pair<int, int>> graph[n];
    for (auto& flight : flights) {
        // flight[0] = from, flight[1] = to, flight[2] = price
        graph[flight[0]].emplace_back(flight[1], flight[2]);
    }

    vector<int> dist(n, INT_MAX);
    queue<Node> q;
    q.push(Node(src, 0, 0));
    dist[src] = 0;

    while (!q.empty()) {
        Node curr = q.front(); q.pop();
        int u = curr.city, cost = curr.cost, stops = curr.stops;

        if (stops > K) continue;

        for (auto& next : graph[u]) {
            int v = next.first, price = next.second;
            // If not exceeding previously found cheaper cost and stops are within limit
            if (cost + price < dist[v] && stops <= K) {
                dist[v] = cost + price;
                q.push(Node(v, dist[v], stops + 1));
            }
        }
    }
    return dist[dst] == INT_MAX ? -1 : dist[dst];
}

int main() {
    int n = 4;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    int src = 0, dst = 3, K = 1;

    int answer = findCheapestPrice(n, flights, src, dst, K);
    cout << "Cheapest Price: " << answer << endl; // Output: 700

    return 0;
}
