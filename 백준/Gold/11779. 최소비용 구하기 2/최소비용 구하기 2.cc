#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int n, m;
int dist[1001];
int via[1001];
vector<pair<int, int>> adjacent[1001];

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
				via[nextNode] = curNode;
			}
		}
	}
}

int main() {
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adjacent[u].push_back({ v, w });
	}

	int start, end;
	cin >> start >> end;

	dijkstra(start);
	vector<int> cities;

	int next = end;
	cities.push_back(end);
	while (1) {
		cities.push_back(via[next]);
		next = via[next];
		if (next == start) break;
	}

	cout << dist[end] << '\n';
	cout << cities.size() << '\n';
	for (int i = cities.size() - 1; i >= 0; i--) {
		cout << cities[i] << ' ';
	}


	return 0;
}