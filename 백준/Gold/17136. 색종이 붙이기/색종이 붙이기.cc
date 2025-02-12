#include <bits/stdc++.h>
using namespace std;

int ans = INT_MAX;
int board[11][11];
int papers[6];

bool check(int size, int r, int c) {
	for (int i = r; i < r + size; i++) {
		for (int j = c; j < c + size; j++) {
			if (board[i][j] == 0) return false;
		}
	}
	return true;
}

void glue(int r, int c, int cnt) {
	int sum = 0;
	bool flag = false;
	while (board[r][c] != 1) {
		sum += board[r][c];
		c++;
		if (c >= 10) {
			r++;
			if (r >= 10) {
				if (sum == 0) flag = true;
				break;
			}
			c = 0;
		}
	}

	if (flag) {
		ans = cnt < ans ? cnt : ans;
	}
	else {
		for (int size = 5; size > 0; size--) {
			if (r + size > 10 || c + size > 10) continue;
			if (papers[size] >= 5) continue;

			if (check(size, r, c)) {
				papers[size]++;
				for (int j = r; j < r + size; j++) {
					for (int k = c; k < c + size; k++) {
						board[j][k] = 0;
					}
				}
				
				/*
				cout << "종이 붙인 후:\n";
				for (int p = 0; p < 10; p++) {
					for (int q = 0; q < 10; q++) {
						cout << board[p][q] << ' ';
					}
					cout << '\n';
				}
				*/
				
				
				glue(r, c, cnt + 1);

				papers[size]--;
				for (int j = r; j < r + size; j++) {
					for (int k = c; k < c + size; k++) {
						board[j][k] = 1;
					}
				}
			}
		}
	}
}

int main() {
	// 색종이의 크기는 1×1, 2×2, 3×3, 4×4, 5×5로 총 다섯 종류가 있으며, 각 종류의 색종이는 5개씩 가지고 있다.
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> board[i][j];
		}
	}

	glue(0, 0, 0);

	ans = ans == INT_MAX ? -1 : ans;

	cout << ans;
}