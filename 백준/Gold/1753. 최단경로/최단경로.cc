#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;

vector<pair<int, int>> adjacent[20001];
int dist[20001];

struct compare { // priority queue compare 함수 이렇게 써야댐 ㅋㅋ 몰랐삼
    bool operator() (pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second > b.second;
    }
};


int main() {
    int v, e;
    cin >> v >> e;
    
    int start;
    cin >> start;
    
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjacent[u].push_back({ v, w });
    }
    
    for (int i = 0; i <= v; i++) {
        dist[i] = INF;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

    pq.push({ start, 0 });
    dist[start] = 0;

    while (!pq.empty()) {
        int curNode = pq.top().first;
        int weightSum = pq.top().second;
        pq.pop();

        if (dist[curNode] < weightSum) continue;

        for (int i = 0; i < adjacent[curNode].size(); i++) {
            int nextNode = adjacent[curNode][i].first;
            int nextWeight = adjacent[curNode][i].second;

            if (dist[nextNode] > weightSum + nextWeight) {
                dist[nextNode] = weightSum + nextWeight;

                pq.push({ nextNode, dist[nextNode] });
            }
        }
    }

    for (int i = 1; i <= v; i++) {
        if (dist[i] == INF) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }

    return 0;
}