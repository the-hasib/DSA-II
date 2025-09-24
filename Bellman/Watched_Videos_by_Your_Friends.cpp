#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

const int MAX = 110;
const int INF = 1000000;

struct Edge {
    int u, v;
};

Edge edges[MAX*MAX];
int edgeCount = 0;
int dist[MAX];
int parent[MAX];

// Add bidirectional edge
void addEdge(int u, int v) {
    edges[edgeCount].u = u;
    edges[edgeCount].v = v;
    edgeCount++;
}

void bellmanFord(int n, int src) {
    for(int i=0;i<n;i++) {
        dist[i]=INF;
        parent[i]=-1;
    }
    dist[src]=0;
    for(int r=1;r<=n-1;r++) {
        for(int j=0;j<edgeCount;j++) {
            int u = edges[j].u, v = edges[j].v;
            if(dist[u]!=INF && dist[u]+1 < dist[v]) {
                dist[v]=dist[u]+1;
                parent[v]=u;
            }
            if(dist[v]!=INF && dist[v]+1 < dist[u]) { // bidirectional edge
                dist[u]=dist[v]+1;
                parent[u]=v;
            }
        }
    }
}

int main() {
    // Example setup for screenshot sample:
    // watchedVideos = [["A","B"],["C"],["B","C"],["D"]]
    // friends = [[1,2],[0,3],[0,3],[1,2]]
    vector<vector<string>> watchedVideos = {{"A","B"},{"C"},{"B","C"},{"D"}};
    vector<vector<int>> friends = {{1,2},{0,3},{0,3},{1,2}};
    int n = watchedVideos.size();
    edgeCount=0;
    // Build undirected graph edges
    for(int i=0;i<n;i++)
        for(int f: friends[i])
            if(i<f) addEdge(i, f); // add each undirected pair once

    int id = 0, level = 1;
    bellmanFord(n, id);

    map<string, int> freq;
    for(int i=0;i<n;i++) {
        if(dist[i]==level) {
            for(auto vid: watchedVideos[i]) freq[vid]++;
        }
    }

    // Sort by freq (increasing), then lexicographically
    vector<pair<string, int>> vfreq(freq.begin(), freq.end());
    sort(vfreq.begin(), vfreq.end(), [](auto &a, auto &b){
        if(a.second!=b.second) return a.second<b.second;
        return a.first<b.first;
    });

    // Print output
    cout << "[";
    for(int i=0;i<vfreq.size();i++) {
        if(i) cout << ",";
        cout << "\"" << vfreq[i].first << "\"";
    }
    cout << "]" << endl;
    return 0;
}
