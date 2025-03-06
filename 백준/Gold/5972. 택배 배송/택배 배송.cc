#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int n, m;
int dist[50001];
vector<pair<int, int>> adjacent[50001];

struct compare {
	bool operator() (pair<int, int> a, pair<int, int> b) {
		if (a.second == b.second) return a.first > b.first;
		return a.second > b.second;
	}
};

void dijkstra(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

	for (int i = 0; i <= n; i++) {
		dist[i] = INF;
	}

	dist[start] = 0;
	pq.push({ start, 0 });

	while (!pq.empty()) {
		int curNode = pq.top().first;
		int weightSum = pq.top().second;
		pq.pop();

		if (dist[curNode] < weightSum) continue;

		for (int i = 0; i < adjacent[curNode].size(); i++) {
			int nextNode = adjacent[curNode][i].first;
			int nextWeight = adjacent[curNode][i].second;

			if (dist[nextNode] > nextWeight + weightSum) {
				dist[nextNode] = nextWeight + weightSum;
				pq.push({ nextNode, dist[nextNode] });
			}
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adjacent[u].push_back({ v, w });
		adjacent[v].push_back({ u, w });
	}

	dijkstra(1);

	cout << dist[n];

	return 0;
}