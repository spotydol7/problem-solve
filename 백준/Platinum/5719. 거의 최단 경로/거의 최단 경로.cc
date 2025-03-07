#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int n, m, s, d;
int dist[501];
vector<int> parent[501];
vector<pair<int, int>> adjacent[501];
int nearest[501][501];

struct compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if(a.second == b.second) return a.first > b.first;
        return a.second > b.second;
    }
};

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

    for (int i = 0; i <= n; i++) {
        dist[i] = INF;
        parent[i].clear();
    }
    dist[start] = 0;
    pq.push({start, 0});
    
    while (!pq.empty()) {
        int curNode = pq.top().first;
        int cost = pq.top().second;
        pq.pop();
        
        if (cost > dist[curNode]) continue;
        
        for (auto &edge : adjacent[curNode]) {
            int nextNode = edge.first;
            int w = edge.second;
            
            if (nearest[curNode][nextNode] == -1) continue;
            if (dist[nextNode] > cost + w) {
                dist[nextNode] = cost + w;
                pq.push({nextNode, dist[nextNode]});
                parent[nextNode].clear();
                parent[nextNode].push_back(curNode);
            }
            else if (dist[nextNode] == cost + w) {
                parent[nextNode].push_back(curNode);
            }
        }
    }
}


void removeShortestPaths(int v) {
    if (v == s) return;
    for (int u : parent[v]) {
        if (nearest[u][v] != -1) {
            nearest[u][v] = -1;
            removeShortestPaths(u);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        cin >> s >> d;

        for (int i = 0; i < 501; i++) {
            for (int j = 0; j < 501; j++) {
                nearest[i][j] = 0;
            }
        }
        for (int i = 0; i <= n; i++) {
            adjacent[i].clear();
        }
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adjacent[u].push_back({v, w});
        }
        
        dijkstra(s);
        if (dist[d] == INF) {
            cout << -1 << "\n";
            continue;
        }
        
        removeShortestPaths(d);
        
        dijkstra(s);
        cout << (dist[d] == INF ? -1 : dist[d]) << "\n";
    }
    
    return 0;
}
