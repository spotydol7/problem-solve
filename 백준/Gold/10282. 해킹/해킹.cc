#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int dist[10001];

struct compare {
	bool operator() (pair<int, int> a, pair<int, int> b) {
		if (a.second == b.second) return a.first > b.first;
		return a.second > b.second;
	}
};

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, d, start;
		cin >> n >> d >> start; // 컴퓨터 개수 n, 의존성 개수 d, 해킹당한 컴퓨터의 번호

		vector<pair<int, int>> adjacent[10001];
		
		for (int i = 0; i < d; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			adjacent[v].push_back({ u, w });
		}

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

		int maxDist = 0;
		int cnt = 0;
		for (int i = 0; i <= n; i++) {
			if (dist[i] < INF) {
				maxDist = max(maxDist, dist[i]);
				cnt++;
			}
		}

		cout << cnt << " " << maxDist << '\n';
	}

	return 0;
}