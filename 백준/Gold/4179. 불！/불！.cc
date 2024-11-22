#include <bits/stdc++.h>
using namespace std;

int r, c;
string maze[1001];
int run[1001][1001];
int fire[1001][1001];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
queue<pair<int, int>> run_q;
queue<pair<int, int>> fire_q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c;
	memset(run, -1, sizeof(run));
	memset(fire, -1, sizeof(fire));

	for (int i = 0; i < r; i++) {
		cin >> maze[i];
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (maze[i][j] == 'J') {
				run_q.push({ j, i });
				run[i][j] = 0;
			}
			if (maze[i][j] == 'F') {
				fire_q.push({ j, i });
				fire[i][j] = 0;
			}
		}
	}

	while (!fire_q.empty()) {
		auto cur = fire_q.front();
		fire_q.pop();
		int x = cur.first;
		int y = cur.second;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= c || ny < 0 || ny >= r) continue;
			if (fire[ny][nx] >= 0 || maze[ny][nx] == '#') continue;

			fire_q.push({ nx, ny });
			fire[ny][nx] = fire[y][x] + 1;
		}
	}

	while (!run_q.empty()) {
		auto cur = run_q.front();
		run_q.pop();
		int x = cur.first;
		int y = cur.second;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= c || ny < 0 || ny >= r) { // maze 가장자리 도착 == 탈출
				cout << run[y][x] + 1;
				return 0;
			}
			if (run[ny][nx] >= 0 || maze[ny][nx] == '#') continue;
			if (fire[ny][nx] != -1 && fire[ny][nx] <= run[y][x] + 1) continue;

			run[ny][nx] = run[y][x] + 1;
			run_q.push({ nx, ny });
		}
	}
	cout << "IMPOSSIBLE";

	return 0;
}