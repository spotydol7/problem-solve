#include <bits/stdc++.h>
using namespace std;

int n;
int cnt_normal = 0;
int cnt_blind = 0;

char normal[102][102];
char blind[102][102];
bool visited[102][102];

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };


void dfs_normal(int curX, int curY) {
	if (visited[curX][curY]) return;

	visited[curX][curY] = true;

	for (int i = 0; i < 4; i++) {
		int nx = curX + dx[i];
		int ny = curY + dy[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n)
			continue;

		if ((normal[nx][ny] == normal[curX][curY]) && !visited[nx][ny]) {
			dfs_normal(nx, ny);
		}
	}
}

void dfs_blind(int curX, int curY) {
	if (visited[curX][curY]) return;

	visited[curX][curY] = true;

	for (int i = 0; i < 4; i++) {
		int nx = curX + dx[i];
		int ny = curY + dy[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n)
			continue;

		if ((blind[nx][ny] == blind[curX][curY]) && !visited[nx][ny]) {
			dfs_blind(nx, ny);
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> normal[i][j];
			if (normal[i][j] == 'G') {
				blind[i][j] = 'R';
			}
			else blind[i][j] = normal[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == false) {
				dfs_normal(i, j);
				cnt_normal++;
			}
		}
	}

	memset(visited, false, sizeof(visited));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == false) {
				dfs_blind(i, j);
				cnt_blind++;
			}
		}
	}

	cout << cnt_normal << ' ' << cnt_blind << '\n';

	return 0;
}