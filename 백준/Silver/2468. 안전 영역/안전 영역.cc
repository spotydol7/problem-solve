#include <bits/stdc++.h>
using namespace std;

int n;
int arr[101][101];
int flood[101][101];
int visited[101][101];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = 1;
	while (!q.empty()) {
		int curx = q.front().first;
		int cury = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = curx + dx[i];
			int ny = cury + dy[i];
			if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;
			if (visited[nx][ny] || flood[nx][ny] == 0) continue;
			q.push({ nx, ny });
			visited[nx][ny] = 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int max = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] > max) max = arr[i][j];
		}
	}
	
	int rain = max;
	
	max = 0;

	while (rain--) {
		int cnt = 0;
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] <= rain) flood[i][j] = 0;
				else flood[i][j] = arr[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (flood[i][j] != 0 && !visited[i][j]) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		if (cnt > max) max = cnt;
	}

	cout << max << '\n';

	return 0;
}