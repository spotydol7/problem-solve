#include <bits/stdc++.h>
using namespace std;
int run[1001][1001];
int fire[1001][1001];
int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int test_case;
	cin >> test_case;

	while (test_case--) {
		queue<pair<int, int>> fire_q;
		queue<pair<int, int>> run_q;
		bool found = false;
		memset(run, -1, sizeof(run));
		memset(fire, -1, sizeof(fire));
		string board[1001];

		int R, C;
		cin >> C >> R;
		for (int i = 0; i < R; i++) {
			cin >> board[i];

			for (int j = 0; j < C; j++) {
				if (board[i][j] == '@') {
					run[i][j] = 0;
					run_q.push({ i, j });
				}
				if (board[i][j] == '*') {
					fire[i][j] = 0;
					fire_q.push({ i, j });
				}
			}
		}

		while (!fire_q.empty()) {
			auto cur = fire_q.front();
			fire_q.pop();
			int cur_r = cur.first;
			int cur_c = cur.second;

			for (int i = 0; i < 4; i++) {
				int nr = cur_r + dr[i];
				int nc = cur_c + dc[i];

				if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
				if (board[nr][nc] == '#' || fire[nr][nc] >= 0) continue;
				fire[nr][nc] = fire[cur_r][cur_c] + 1;
				fire_q.push({ nr, nc });
			}
		}

		while (!run_q.empty() && !found) {
			auto cur = run_q.front();
			run_q.pop();
			int cur_r = cur.first;
			int cur_c = cur.second;

			for (int i = 0; i < 4; i++) {
				int nr = cur_r + dr[i];
				int nc = cur_c + dc[i];

				if (nr < 0 || nr >= R || nc < 0 || nc >= C) {
					found = true;
					cout << run[cur_r][cur_c] + 1 << '\n';
					break;
				}

				if (board[nr][nc] == '#' || run[nr][nc] >= 0) continue;
				if (fire[nr][nc] >= 0 && fire[nr][nc] <= run[cur_r][cur_c] + 1) continue;
				run[nr][nc] = run[cur_r][cur_c] + 1;
				run_q.push({ nr, nc });
			}
		}

		if (!found) cout << "IMPOSSIBLE" << '\n';
	}

	return 0;
}