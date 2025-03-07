#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;

using namespace std;

int n, m, k;
vector<pair<int, int>> adjacent[1001];
priority_queue<ll> ans[1001]; // 이건 그냥 내림차순 ㅇㅇㅇ
ll dist[1001];

struct compare {
	bool operator()(pair<int, ll> a, pair<int, ll> b) {
		if (a.second == b.second) return a.first > b.first;
		return a.second > b.second;
	}
};

void dijkstra(int start) {
	priority_queue<pair<int, ll>, vector<pair<int, ll>>, compare> pq;

	for (int i = 0; i <= n; i++)
		dist[i] = INF;

	dist[start] = 0;
	pq.push({ start, 0 });
	ans[start].push(0);

	while (!pq.empty()) {
		int curNode = pq.top().first;
		ll weightSum = pq.top().second;
		pq.pop();

		//if (dist[curNode] < weightSum) continue;

		for (int i = 0; i < adjacent[curNode].size(); i++) {
			int nextNode = adjacent[curNode][i].first;
			ll nextWeight = adjacent[curNode][i].second;

			dist[nextNode] = nextWeight + weightSum;
			if (ans[nextNode].size() == k) {
				if (ans[nextNode].top() > dist[nextNode]) {
					ans[nextNode].pop();
					ans[nextNode].push(dist[nextNode]);
					pq.push({ nextNode, dist[nextNode] });
				}
			}
			else {
				ans[nextNode].push(dist[nextNode]);
				pq.push({ nextNode, dist[nextNode] });
			}
		}
	}
}

int main() {
	cin >> n >> m >> k; // k번째로 최단인 경로
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adjacent[u].push_back({ v, w });
	}

	dijkstra(1);

	for (int i = 1; i <= n; i++) {
		if (ans[i].size() != k) cout << -1 << '\n';
		else cout << ans[i].top() << '\n';
	}

	return 0;
}

/*

5 10 2
1 2 2
1 3 7
1 4 5
1 5 6
2 4 2
2 3 4
3 4 6
3 5 8
5 2 4
5 4 1

ans
-1
10
7
5
14

*/