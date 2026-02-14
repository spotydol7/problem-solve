#include <bits/stdc++.h>
using namespace std;

int N, M;
bool light[101][101];
bool visited[101][101];
int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };
vector<pair<int, int>> turnOn[101][101];
queue<pair<int, int>> q;

bool isConnected(int r, int c) {
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
			if (visited[nr][nc]) return true;
		}
	}
	return false;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		x--; y--; a--; b--;

		turnOn[x][y].push_back({ a, b });
	}

	queue<pair<int, int>> q;
	light[0][0] = true;
	visited[0][0] = true;
	q.push({ 0, 0 });

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		int curR = cur.first;
		int curC = cur.second;

		for (int i = 0; i < turnOn[curR][curC].size(); i++) {
			auto on = turnOn[curR][curC][i];
			light[on.first][on.second] = true;

			if (!visited[on.first][on.second] && isConnected(on.first, on.second)) {
				visited[on.first][on.second] = true;
				q.push({ on.first, on.second });
			}
		}

		for (int i = 0; i < 4; i++) {
			int nr = curR + dr[i];
			int nc = curC + dc[i];

			if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
			if (visited[nr][nc] || !light[nr][nc]) continue;

			q.push({ nr, nc });
			visited[nr][nc] = true;
		}
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (light[i][j]) cnt++;
		}
	}

	cout << cnt << '\n';

	return 0;
}