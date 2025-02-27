#include<bits/stdc++.h>
using namespace std;

int r, c;
int board[10001][501];
int dr[] = {-1, 0, 1};
int dc[] = { 1, 1, 1 };
int ans;

bool backtrack(int row, int column) {
	if (column == c - 1) {
		ans++;
		return true;
	}

	board[row][column] = 0;

	for (int i = 0; i < 3; i++) {
		int nr = row + dr[i];
		int nc = column + dc[i];
		if (nr >= 0 && nr < r && nc >= 0 && nc < c && board[nr][nc] == 1) {
			if (backtrack(nr, nc)) return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < c; j++) {
			if (str[j] == '.') board[i][j] = 1;
			else board[i][j] = 0;
		}
	}
	
	for (int i = 0; i < r; i++) {
		backtrack(i, 0);
	}
	
	cout << ans;

	return 0;
}