#include <bits/stdc++.h>
#define INF LLONG_MAX
using namespace std;

int n, m, k;
vector<pair<int, int>> adjacent[100001];
long long dist[100001];

struct compare {
	bool operator() (pair<int, long long> a, pair<int, long long> b) {
		if (a.second == b.second) return a.first < b.first;
		return a.second > b.second;
	}
};

priority_queue<pair<int, long long>, vector<pair<int, long long>>, compare> pq;

void dijkstra() {
	while (!pq.empty()) {
		int curNode = pq.top().first;
		long long weightSum = pq.top().second;
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
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adjacent[v].push_back({ u, w });
	}

	vector<int> interviews;

	for (int i = 0; i <= n; i++) {
		dist[i] = INF;
	}

	for (int i = 0; i < k; i++) {
		int temp;
		cin >> temp;
		
		dist[temp] = 0;
		pq.push({ temp, 0 });
		interviews.push_back(temp);
	}
	
	dijkstra();

	long long minD = INF;
	long long maxD = -1;
	int maxCity;
	for (int i = 1; i <= n; i++) {
		if (dist[i] > maxD) {
			maxD = dist[i];
			maxCity = i;
		}
	}


	cout << maxCity << '\n' << maxD;

	return 0;
}

/*

6 10 2
2 6 2
1 4 1
6 1 5
2 5 1
5 1 4
4 5 6
6 2 3
3 5 1
3 1 1
5 2 2
1 2

ans:
4
8

*/