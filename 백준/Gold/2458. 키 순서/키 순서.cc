#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int visited[501];
vector<int> smaller[501];
vector<int> taller[501];

int bfs_small(int start) {
	memset(visited, 0, sizeof(visited));
	int cnt = 0;
	queue<int> q;
	q.push(start);
	visited[start] = 1;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < smaller[cur].size(); i++) {
			int next = smaller[cur][i];
			if (visited[next]) continue;
			visited[next] = 1;
			q.push(next);
			cnt++;
		}
	}
	return cnt;
}

int bfs_tall(int start) {
	memset(visited, 0, sizeof(visited));
	int cnt = 0;
	queue<int> q;
	q.push(start);
	visited[start] = 1;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < taller[cur].size(); i++) {
			int next = taller[cur][i];
			if (visited[next]) continue;
			visited[next] = 1;
			q.push(next);
			cnt++;
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	smaller->clear();
	taller->clear();
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b; // a가 b보다 키가 작다, a -> b
		smaller[a].push_back(b);
		taller[b].push_back(a);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (bfs_small(i) + bfs_tall(i) == n - 1) {
			ans++;
		}
	}

	cout << ans;

	return 0;
}