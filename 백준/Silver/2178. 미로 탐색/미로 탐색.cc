#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[101][101];
int dist[101][101];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
queue<pair<int, int>> q;

void bfs() {
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			if (dist[ny][nx] >= 0 || arr[ny][nx] != 1) continue;

			q.push({ nx, ny });
			dist[ny][nx] = dist[cur.second][cur.first] + 1;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	memset(dist, -1, sizeof(dist));

	q.push({ 0, 0 });
	dist[0][0] = 0;

	bfs();
	cout << dist[n - 1][m - 1] + 1 << '\n';

	return 0;
}