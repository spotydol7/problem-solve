#include <bits/stdc++.h>
using namespace std;

int m, n, k;
int board[101][101];
int visited[101][101];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int cnt = 0;
vector<int> ans;

void bfs(int x, int y) {
	queue <pair<int, int>> q;
	int area = 0;
	q.push({ x, y });
	while (!q.empty()) {
		int curx = q.front().first;
		int cury = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = curx + dx[i];
			int ny = cury + dy[i];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			if (visited[nx][ny] != 0 || board[nx][ny] == 1) continue;
			visited[nx][ny] = cnt;
			q.push({ nx, ny });
			area++;
		}
	}
	if (area > 0)
		ans.push_back(area);
	else ans.push_back(1);
}

int main() {
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2; // 0 2 4 4
		cin >> x1 >> y1 >> x2 >> y2;

		for (int j = x1; j < x2; j++) {
			for (int k = y1; k < y2; k++) {
				board[k][j] = 1;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 0 && visited[i][j] == 0) {
				cnt++;
				bfs(i, j);
			}
		}
	}

	sort(ans.begin(), ans.end());
	cout << cnt << '\n';
	for (auto iter = ans.begin(); iter != ans.end(); iter++) {
		cout << *iter << ' ';
	}

	return 0;
}