#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int n, m, r;
int ans;
int items[101];
int dist[101];
vector<pair<int, int>> adjacent[101];

struct compare {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.second == b.second) return a.first > b.first;
		return a.second > b.second;
	}
};

void dijkstra(int start) {
	ans = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

	int copy_items[101];

	for (int i = 0; i <= n; i++) {
		dist[i] = INF;
		copy_items[i] = items[i];
	}

	dist[start] = 0;
	pq.push({ start, 0 });
	ans += copy_items[start];
	copy_items[start] = 0;

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

			if (dist[nextNode] <= m) {
				ans += copy_items[nextNode];
				copy_items[nextNode] = 0;
			}
		}
	}
}

int main() {
	cin >> n >> m >> r; // 지역의 개수 n (1 ≤ n ≤ 100)과 예은이의 수색범위 m (1 ≤ m ≤ 15), 길의 개수 r (1 ≤ r ≤ 100)
	int maxItem = 0;
	for (int i = 1; i <= n; i++) {
		int temp;
		cin >> temp;
		items[i] = temp;
		maxItem = max(maxItem, items[i]);
	}

	for (int i = 0; i < r; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adjacent[u].push_back({ v, w });
		adjacent[v].push_back({ u, w });
	}

	int maxAns = -1;

	for (int i = 1; i <= n; i++) {
		dijkstra(i);
		maxAns = max(ans, maxAns);
	}

	if (r == 0) maxAns = maxItem;
	cout << maxAns;

	return 0;
}