#include <bits/stdc++.h>
using namespace std;

int n, cnt;
int grid[26][26];
int numgrid[26][26];
bool visited[26][26];
vector<int> apartnum;
int num;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int curX, int curY) {
	if (visited[curX][curY]) return;

	visited[curX][curY] = true;
	
	for (int i = 0; i < 4; i++) {
		int nx = curX + dx[i];
		int ny = curY + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

		if (grid[nx][ny] == grid[curX][curY] && !visited[nx][ny]) {
			numgrid[curX][curY] = cnt;
			numgrid[nx][ny] = cnt;
			num++;
			dfs(nx, ny);
		}
	}
}

int main() {
	cin >> n;
	vector<int> ans;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &grid[i][j]);
			numgrid[i][j] = grid[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] != 0 && !visited[i][j]) {
				cnt++;
				num = 1;
				dfs(i, j);
				apartnum.push_back(num);
			}
		}
	}

	sort(apartnum.begin(), apartnum.end());

	cout << cnt << '\n';

	for (auto iter = apartnum.begin(); iter != apartnum.end(); iter++) {
		cout << *iter << '\n';
	}

	return 0;
}