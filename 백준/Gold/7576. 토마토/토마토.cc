#include <bits/stdc++.h>
using namespace std;

int tomato[1001][1001];
int dist[1001][1001];
int m, n;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
queue<pair<int, int>> q;

void bfs() {
	while (!q.empty()) {
		auto cur = q.front();
		int x = cur.first;
		int y = cur.second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			if (dist[ny][nx] >= 0) continue;
			dist[ny][nx] = dist[y][x] + 1;
			q.push({ nx, ny });
		}
	}
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1) {
				q.push({ j, i });
			}
			if (tomato[i][j] == 0) {
				dist[i][j] = -1;
			}
		}
	}

	bfs();

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] == -1) {
				cout << -1 << '\n';
				return 0;
			}
			ans = max(ans, dist[i][j]);	
		}
	}

	cout << ans << '\n';

	return 0;
}