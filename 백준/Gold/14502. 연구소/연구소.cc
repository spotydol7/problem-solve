#include<bits/stdc++.h>
using namespace std;

int n, m, ans = 0;
int arr[9][9];
int wall_arr[9][9];
int visited[9][9];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
queue<pair<int, int>> q;

void bfs(int x, int y) {
	q.push({ x, y });
	visited[x][y] = 1;

	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (visited[nx][ny] || wall_arr[nx][ny] != 0) continue;
			q.push({ nx, ny });
			visited[nx][ny] = 1;
			wall_arr[nx][ny] = 2;
		}
	}
}

void putWall(int wall) {
	int cnt = 0;
	if (wall == 3) {
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				wall_arr[i][j] = arr[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (wall_arr[i][j] == 2 && !visited[i][j]) {
					bfs(i, j);
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (wall_arr[i][j] == 0) cnt++;
			}
		}

		if (cnt > ans) ans = cnt;
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 0 && arr[i][j] == 0) {
					arr[i][j] = 1;
					putWall(wall + 1);
					arr[i][j] = 0;
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	putWall(0);

	cout << ans;

	return 0;
}