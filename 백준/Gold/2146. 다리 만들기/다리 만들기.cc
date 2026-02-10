#include <bits/stdc++.h>
using namespace std;

int N;
int board[101][101];
bool visited[101][101];
int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };

bool check(int r, int c) {
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
		if (board[nr][nc] == 0) return true;
	}
	return false;
}

int main() {
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 0 || visited[i][j]) continue;
			cnt++;
			queue<pair<int, int>> q;
			q.push({ i, j });
			visited[i][j] = true;
			board[i][j] = cnt;

			while (!q.empty()) {
				auto cur = q.front(); q.pop();
				int cur_r = cur.first;
				int cur_c = cur.second;
				for (int dir = 0; dir < 4; dir++) {
					int nr = cur_r + dr[dir];
					int nc = cur_c + dc[dir];

					if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
					if (visited[nr][nc] || board[nr][nc] == 0) continue;

					board[nr][nc] = cnt;
					visited[nr][nc] = true;
					q.push({ nr, nc });
				}
			}
		}
	}

	int answer = 99999999;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] != 0 && check(i, j)) {

				bool visited_bfs[101][101] = { false, };
				
				queue<pair<pair<int, int>, int>> q;
				q.push({ {i, j}, 0 });
				visited_bfs[i][j] = true;
				int curColor = board[i][j];

				while (!q.empty()) {
					auto cur = q.front(); q.pop();
					int cur_r = cur.first.first;
					int cur_c = cur.first.second;
					int cur_step = cur.second;

					if (board[cur_r][cur_c] != 0 && board[cur_r][cur_c] != curColor) {
						answer = min(answer, cur_step - 1);
						break;
					}

					for (int dir = 0; dir < 4; dir++) {
						int nr = cur_r + dr[dir];
						int nc = cur_c + dc[dir];

						if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
						if (visited_bfs[nr][nc] || board[nr][nc] == curColor) continue;

						visited_bfs[nr][nc] = true;
						q.push({ {nr, nc},  cur_step + 1});
					}
				}
			}
		}
	}

	cout << answer << '\n';

	return 0;
}