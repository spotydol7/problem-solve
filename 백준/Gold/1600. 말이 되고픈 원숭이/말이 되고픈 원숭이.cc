#include <bits/stdc++.h>
using namespace std;

int K, C, R;
int board[201][201];
bool visited[201][201][31]; // R, C, K
int dr[12] = { -2, -1, 1, 2, 2, 1, -1, -2, 1, -1, 0, 0 };
int dc[12] = { 1, 2, 2, 1, -1, -2, -2, -1, 0, 0, 1, -1 };

int main() {
	cin >> K >> C >> R;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
		}
	}

	queue<tuple<int, int, int, int>> q; // R, C, step, K
	q.push({ 0, 0, 0, 0 });
	visited[0][0][0] = true;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		int curR = get<0>(cur);
		int curC = get<1>(cur);
		int curStep = get<2>(cur);
		int curK = get<3>(cur);

		if (curR == R - 1 && curC == C - 1) {
			cout << curStep << '\n';
			return 0;
		}

		for (int i = 0; i < 12; i++) {
			if (i >= 0 && i <= 7 && curK >= K) continue;
			int nr = curR + dr[i];
			int nc = curC + dc[i];
			int nK = i >= 0 && i <= 7 ? curK + 1 : curK;

			if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
			if (visited[nr][nc][nK] || board[nr][nc] != 0) continue;

			visited[nr][nc][nK] = true;
			q.push({ nr, nc, curStep + 1, nK });
		}
	}

	cout << -1 << '\n';

	return 0;
}