#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, d, ans;
vector<pair<int, int>> adjacent[1001];
int dist[1001][1001];
int visited[1001];

int bfs(int a, int b) {
	int dis = 0;
	queue<pair<int, int>> q;
	q.push({ a, dis });
	visited[a] = 1;
	
	while (!q.empty()) {
		int cur = q.front().first;
		int cur_dist = q.front().second;
		q.pop();

		if (cur == b) return cur_dist;
		for (int i = 0; i < adjacent[cur].size(); i++) {
			int next = adjacent[cur][i].first;
			int n_dist = adjacent[cur][i].second;
			if (!visited[next]) {
				visited[next] = 1;
				q.push({ next, cur_dist + n_dist });
			}
		}
	}

	return -1;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> d;
		adjacent[a].push_back({ b, d });
		adjacent[b].push_back({ a, d });
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		memset(visited, 0, sizeof(visited));
		ans = bfs(a, b);
		cout << ans << '\n';
	}
	return 0;
}