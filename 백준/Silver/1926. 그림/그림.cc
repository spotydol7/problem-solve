#include <bits/stdc++.h>
using namespace std;

int n, m;
int cnt = 0;
int arr[501][501];
int visited[501][501];

void floodfill(int x, int y) {
	if (x < 0 || x >= m || y < 0 || y >= n) return;
	if (visited[y][x] || arr[y][x] != 1) return;
	if (arr[y][x] != 1) return;

	visited[y][x] = 1;
	arr[y][x] = 2;
	cnt++;

	floodfill(x + 1, y);
	floodfill(x - 1, y);
	floodfill(x, y + 1);
	floodfill(x, y - 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	int max = 0;
	int zone_cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1 && !visited[i][j]) {
				cnt = 0;
				zone_cnt++;
				floodfill(j, i);
				if (cnt > max) max = cnt;
			}
		}
	}

	cout << zone_cnt << '\n' << max << '\n';
	return 0;
}