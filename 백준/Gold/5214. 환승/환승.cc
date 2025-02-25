#include <bits/stdc++.h>
using namespace std;

int n, k, m;
vector<vector<int>> graph; // 1부터 n까지는 역, n + 1 부터 n + m 하이퍼튜브

int bfs() {
	vector<int> dist(graph.size(), -1);
	queue<int> q;
	dist[1] = 1; // 1번 역 시작
	q.push(1);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == n) return dist[cur];
		for (auto next : graph[cur]) {
			if (dist[next] != -1) continue;
			dist[next] = dist[cur] + 1;
			q.push(next);
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k >> m;
	// 역 n개 튜브 m개, 인덱스 1부터 시작하니까 1 더해줌
	graph.resize(n + m + 1);

	// 각 하이퍼튜브에 대해 튜브 노드의 번호는 n + i
	for (int i = 1; i <= m; i++) {
		vector<int> stations(k);
		for (int j = 0; j < k; j++) {
			cin >> stations[j];
			// 정거장과 하이퍼튜브 연결
			graph[stations[j]].push_back(n + i);
			graph[n + i].push_back(stations[j]);
		}
	}

	// BFS 결과에서 튜브를 거칠 때마다 이동 횟수 1더해지니까 실제 역 사이 이동 횟수는 (bfs 리턴값 + 1) / 2
	int ans = bfs();
	if (ans == -1) cout << -1;
	else cout << (ans + 1) / 2;
	return 0;
}