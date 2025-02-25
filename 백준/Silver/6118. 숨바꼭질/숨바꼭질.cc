#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adjacent[20003];
bool visited[20003];
int ans[20003];
int maxDepth = -1;

void bfs(int x) {
	queue<pair<int, int>> q;
	q.push({ x, 0 });
	visited[x] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		int curDepth = q.front().second;
		maxDepth = max(maxDepth, curDepth);
		q.pop();
		for (int i = 0; i < adjacent[cur].size(); i++) {
			int next = adjacent[cur][i];
			if (visited[next]) continue;
			visited[next] = true;
			q.push({ next, curDepth + 1 });
			ans[next] = curDepth + 1;
			
		}
	}
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adjacent[a].push_back(b);
		adjacent[b].push_back(a);
	}

	memset(visited, false, sizeof(visited));
	bfs(1);

	int cnt = 0;
	int temp = 0;
	for (int i = 1; i <= n; i++) {
		if (ans[i] == maxDepth) {
			cout << i << ' ' << maxDepth;
			cnt++;
			temp = i + 1;
			break;
		}
	}

	for (int i = temp; i <= n; i++) {
		if (ans[i] == maxDepth) cnt++;
	}

	cout << ' ' << cnt;

	return 0;
}