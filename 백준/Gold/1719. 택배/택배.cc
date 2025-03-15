#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int, int>>> graph(n + 1);
    vector<vector<int>> nextNode(n + 1, vector<int>(n + 1, -1));

    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({ v, w });
        graph[v].push_back({ u, w });
        nextNode[u][v] = v;
        nextNode[v][u] = u;
    }

    
    for (int start = 1; start <= n; start++) {
        vector<int> dist(n + 1, INF);
        dist[start] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({ 0, start });

        while (!pq.empty()) {
            int d = pq.top().first;
            int cur = pq.top().second;
            pq.pop();
            if (d != dist[cur]) continue;

            for (auto &edge : graph[cur]) {
                int nxt = edge.first, w = edge.second;
                if (dist[nxt] > dist[cur] + w) {
                    dist[nxt] = dist[cur] + w;
                    pq.push({ dist[nxt], nxt });
                    
                    if (cur == start)
                        nextNode[start][nxt] = nxt;
                    else
                        nextNode[start][nxt] = nextNode[start][cur];
                }
            }
        }
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                cout << "- ";
            else
                cout << nextNode[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
