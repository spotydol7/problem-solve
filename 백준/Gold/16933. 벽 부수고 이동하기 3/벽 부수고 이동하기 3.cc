#include <bits/stdc++.h>
using namespace std;

int R, C, K;
int board[1001][1001];
bool visited[1001][1001][11][2]; // r, c, k, night(1이 낮)
int dr[5] = { 1, -1, 0, 0 };
int dc[5] = { 0, 0, 1, -1 };

int main() {
	cin >> R >> C >> K;
	for (int i = 0; i < R; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < C; j++) {
			board[i][j] = str[j] - '0';
		}
	}

	queue<tuple<int, int, int, bool, int>> q; // r, c, k, night, step
	q.push({ 0, 0, 0, true, 0 });
	visited[0][0][0][1] = true;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		int curR = get<0>(cur);
		int curC = get<1>(cur);
		int curK = get<2>(cur);
		bool curIsDay = get<3>(cur);
		int curStep = get<4>(cur);

		if (curR == R - 1 && curC == C - 1) {
			cout << curStep + 1 << '\n';
			return 0;
		}

		for (int i = 0; i < 5; i++) {
			int nr = curR + dr[i];
			int nc = curC + dc[i];

			if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;

			// 다음 칸이 0
			if (board[nr][nc] == 0) {
				if (!visited[nr][nc][curK][!curIsDay]) {
					visited[nr][nc][curK][!curIsDay] = true;
					q.push({ nr, nc, curK, !curIsDay, curStep + 1 });
				}
			}
			// 다음 칸이 1
			else if (board[nr][nc] == 1 && curK < K) {
				// 낮이면 부수고 이동
				if (curIsDay) {
					if (!visited[nr][nc][curK + 1][!curIsDay]) {
						visited[nr][nc][curK + 1][!curIsDay] = true;
						q.push({ nr, nc, curK + 1, !curIsDay, curStep + 1 });
					}
				}
				// 밤이면 제자리에서 낮 기다림
				else {
					if (!visited[curR][curC][curK][!curIsDay]) {
						visited[curR][curC][curK][!curIsDay] = true;
						q.push({ curR, curC, curK, !curIsDay, curStep + 1 });
					}
				}
			}
		}
	}

	cout << -1 << '\n';

	return 0;
}