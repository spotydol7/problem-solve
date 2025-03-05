#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;

struct compare {
	bool operator() (pair<int, int> a, pair<int, int> b) {
		if (a.second == b.second) return a.first < b.first;
		return a.second > b.second;
	}
};

int n, m, x;
vector<pair<int, int>> adjacent[1001];
int dist[1001];
int back[1001];

void dijkstra(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

	for (int i = 0; i <= n; i++) {
		dist[i] = INF;
	}

	dist[start] = 0;
	pq.push({ start, 0 });
	
	while (!pq.empty()) {
		auto cur = pq.top();
		int curNode = cur.first;
		int weightSum = cur.second;
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
}

int main() {
	
	cin >> n >> m >> x;

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adjacent[u].push_back({ v, w });
	}

	int ans = -1;

	dijkstra(x);
	for (int i = 1; i <= n; i++) {
		back[i] = dist[i];
	}

	for (int i = 1; i <= n; i++) {
		dijkstra(i);
		int go = dist[x];
		ans = max(ans, go + back[i]);
	}

	cout << ans;

	return 0;
}

/*
4 8 2
1 2 4
1 3 2
1 4 7
2 1 1
2 3 5
3 1 2
3 4 4
4 2 3

ans : 10
*/