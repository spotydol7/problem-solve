#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adjacent[10001];
int ans[10001];
bool visited[10001];
int maxCnt = -1;

void bfs(int x) {
	int cnt = 0;
	queue<int> q;
	q.push(x);
	visited[x] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < adjacent[cur].size(); i++) {
			int next = adjacent[cur][i];
			if (visited[next]) continue;
			q.push(next);
			visited[next] = true;
			cnt++;
		}
	}
	maxCnt = cnt > maxCnt ? cnt : maxCnt;
	ans[x] = cnt;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adjacent[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));
		bfs(i);
	}

	for (int i = 1; i <= n; i++) {
		if (ans[i] == maxCnt) cout << i << ' ';
	}

	return 0;
}