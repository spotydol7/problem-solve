#include <bits/stdc++.h>
using namespace std;

int R, C, P;
int board[1001][1001];
int canMove[10];
int castles[10];
int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };

queue<pair<int, int>> q[10];

int main() {
	cin >> R >> C >> P;
	
	for (int i = 1; i <= P; i++) {
		cin >> canMove[i];
	}

	int wallCnt = 0;
	for (int i = 0; i < R; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < C; j++) {
			if (str[j] == '#') {
				board[i][j] = -1;
			}
			if (str[j] - '0' > 0 && str[j] - '0' < 10) {
				int player = str[j] - '0';
				board[i][j] = player;
				q[player].push({ i, j });
				castles[player]++;
			}
		}
	}
	while (true) {
		bool isMoved = false;

		for (int player = 1; player <= P; player++) {
			if (q[player].empty()) continue;

			for (int step = 0; step < canMove[player]; step++) {
				int qSize = q[player].size();

				if (qSize == 0) break;

				while (qSize--) {
					int curR = q[player].front().first;
					int curC = q[player].front().second;
					q[player].pop();

					for (int i = 0; i < 4; i++) {
						int nr = curR + dr[i];
						int nc = curC + dc[i];

						if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;

						if (board[nr][nc] == 0) {
							board[nr][nc] = player;
							castles[player]++;
							q[player].push({ nr, nc });
							isMoved = true;
						}
					}
				}
			}
		}

		if (!isMoved) break;
	}

	for (int i = 1; i <= P; i++) {
		cout << castles[i] << ' ';
	}

	return 0;
}