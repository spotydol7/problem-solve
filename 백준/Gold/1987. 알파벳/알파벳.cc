#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int R, C;
bool visited[27];
char board[21][21];
int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };
int ans = 0;

void backtracking(int r, int c, int depth) {
	ans = max(ans, depth);

	for (int i = 0; i < 4; i++){
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
		
		int alphabetIdx = board[nr][nc] - 'A';
		if (visited[alphabetIdx]) continue;

		visited[alphabetIdx] = true;
		backtracking(nr, nc, depth + 1);
		visited[alphabetIdx] = false;
	}
}

int main() {
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
		}
	}

	visited[board[0][0] - 'A'] = true;
	backtracking(0, 0, 1);

	cout << ans;

	return 0;
}