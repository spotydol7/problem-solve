#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, d;
vector<pair<int, int>> graph[1001];
int dist[1001];

void dijkstra(int a) {
	fill(dist, dist + 1001, INT_MAX);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, a });
	dist[a] = 0;

	while (!pq.empty()) {
		int curNode = pq.top().second;
		int curDist = pq.top().first;
		pq.pop();

		if (dist[curNode] < curDist) continue;

		for (int i = 0; i < graph[curNode].size(); i++) {
			int nextNode = graph[curNode][i].first;
			int nextDist = graph[curNode][i].second + curDist;

			if (dist[nextNode] > nextDist) {
				pq.push({ nextDist, nextNode });
				dist[nextNode] = nextDist;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> d;
		graph[a].push_back({ b, d });
		
	}
	cin >> a >> b;
	dijkstra(a);
	cout << dist[b];

	return 0;
}