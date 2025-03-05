#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int dist[801];
int N, E;
vector<pair<int, int>> adjacent[801];

struct compare {
	bool operator() (pair<int, int> a, pair<int, int> b) {
		if (a.second == b.second) return a.first > b.first;
		return a.second > b.second;
	}
};

void dijkstra(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

	for (int i = 0; i <= N; i++) {
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

			if (dist[nextNode] > weightSum + nextWeight) {
				dist[nextNode] = weightSum + nextWeight;
				pq.push({ nextNode, dist[nextNode] });
			}
		}
	}

}

int main() {
	
	cin >> N >> E;

	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adjacent[u].push_back({ v, w });
		adjacent[v].push_back({ u, w });
	}

	int v1, v2;
	cin >> v1 >> v2;

	dijkstra(1);
	int toV1 = dist[v1];
	int toV2 = dist[v2];

	dijkstra(v1);
	int v1Tov2 = dist[v2];
	int v1ToN = dist[N];

	dijkstra(v2);
	int v2Tov1 = dist[v1];
	int v2ToN = dist[N];

	int a = toV1 + v1Tov2 + v2ToN; // v1 -> v2 -> N
	int b = toV2 + v2Tov1 + v1ToN; // v2 -> v1 -> N

	int ans = min(a, b);
	if (ans >= INF) cout << -1;
	else if (ans < 0) cout << -1;
	else cout << ans;

	return 0;
}