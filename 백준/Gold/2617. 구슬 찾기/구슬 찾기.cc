#include <bits/stdc++.h>
using namespace std;

vector<int> adjacent[100];
vector<int> r_adjacent[100];
bool visited[101];

int bfs(int x, vector<int> v[]) {
	memset(visited, false, sizeof(visited));
	queue<int> q;
	q.push(x);
	visited[x] = true;

	int cnt = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			if (visited[next]) continue;
			q.push(next);
			visited[next] = true;
			cnt++;
		}
	}

	return cnt;
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adjacent[a].push_back(b);
		r_adjacent[b].push_back(a);
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (bfs(i, adjacent) > n / 2 || bfs(i, r_adjacent) > n / 2) cnt++;
	}

	cout << cnt;

	return 0;
}