#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[1001][1001];
bool visited[1001][1001][2];
int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };

int bfs(int r, int c) {
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ { r, c }, { 0, 1 } });
	visited[r][c][0] = true;

	while (!q.empty()) {
		auto cur = q.front();
		int curR = cur.first.first;
		int curC = cur.first.second;
		int curWall = cur.second.first;
		int curDist = cur.second.second;
		q.pop();

		if (curR == N - 1 && curC == M - 1) return curDist;
		
		for (int i = 0; i < 4; i++) {
			int nr = curR + dr[i];
			int nc = curC + dc[i];

			if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

			if (board[nr][nc] == 0 && !visited[nr][nc][curWall]) {
				visited[nr][nc][curWall] = true;
				q.push({ {nr, nc}, {curWall, curDist + 1} });
			}
			if (board[nr][nc] == 1 && curWall == 0 && !visited[nr][nc][1]) {
				visited[nr][nc][1] = true;
				q.push({ {nr, nc}, {1, curDist + 1} });
			}
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) {
			board[i][j] = str[j] - '0';
		}
	}

	cout << bfs(0, 0);

	return 0;
}