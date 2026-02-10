#include <bits/stdc++.h>
using namespace std;

int R, C;
int board[301][301];
int tmp_board[301][301];
bool visited[301][301];
int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };

bool check() {
	memset(visited, false, sizeof(visited));

	int cnt = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (!visited[i][j] && board[i][j] > 0) {
				queue<pair<int, int>> q;
				q.push({ i, j });
				visited[i][j] = true;

				while (!q.empty()) {
					int curR = q.front().first;
					int curC = q.front().second;
					q.pop();

					for (int dir = 0; dir < 4; dir++) {
						int nr = curR + dr[dir];
						int nc = curC + dc[dir];

						if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
						if (visited[nr][nc] || board[nr][nc] == 0) continue;
						visited[nr][nc] = true;
						q.push({ nr, nc });
					}
				}
				cnt++;
			}
		}
	}

	if (cnt >= 2) return true;
	return false;
}

int count_zeros(int r, int c) {
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
		if (board[nr][nc] == 0) ret++;
	}
	return ret;
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
		}
	}

	int year = 0;
	while (true) {
		int cnt = 0;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cnt += board[i][j];
			}
		}

		if (cnt == 0) {
			cout << 0 << '\n';
			return 0;
		}

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (board[i][j] > 0) {
					tmp_board[i][j] = board[i][j] - count_zeros(i, j) >= 0 ? board[i][j] - count_zeros(i, j) : 0;
				}
			}
		}

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				board[i][j] = tmp_board[i][j];
			}
		}
		year++;

		if (check()) {
			cout << year << '\n';
			return 0;
		}
	}

	return 0;
}