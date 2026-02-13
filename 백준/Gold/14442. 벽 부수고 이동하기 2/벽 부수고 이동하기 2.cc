#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int board[1001][1001];
bool visited[1001][1001][11];
int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };

int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) {
			board[i][j] = str[j] - '0';
		}
	}

	queue<tuple<int, int, int, int>> q; // r, c, k, step
	q.push({ 0, 0, 0, 0 });
	visited[0][0][0] = true;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		int curR = get<0>(cur);
		int curC = get<1>(cur);
		int curK = get<2>(cur);
		int curStep = get<3>(cur);

		if (curR == N - 1 && curC == M - 1) {
			cout << curStep + 1 << '\n';
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int nr = curR + dr[i];
			int nc = curC + dc[i];

			if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
			// 벽이 아닐 경우
			if (board[nr][nc] == 0) {
				if (!visited[nr][nc][curK]) {
					visited[nr][nc][curK] = true;
					q.push({ nr, nc, curK, curStep + 1 });
				}
			}
			// 벽인 경우
			else if (board[nr][nc] == 1) {
				// 벽을 더 부술 수 있고 해당 횟수로 방문한 적이 없을 때만
				if (curK < K && !visited[nr][nc][curK + 1]) {
					visited[nr][nc][curK + 1] = true;
					q.push({ nr, nc, curK + 1, curStep + 1 });
				}
			}
		}
	}

	cout << -1 << '\n';


	return 0;
}