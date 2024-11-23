#include <bits/stdc++.h>
using namespace std;

int m, n, K;
int arr[51][51];
int visited[51][51];

void floodfill(int x, int y) {
	if (x < 0 || x >= m || y < 0 || y >= n) return;
	if (visited[y][x] || arr[y][x] != 1) return;

	visited[y][x] = 1;
	arr[y][x] = 2;

	floodfill(x + 1, y);
	floodfill(x - 1, y);
	floodfill(x, y + 1);
	floodfill(x, y - 1);
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		memset(arr, 0, sizeof(arr));
		memset(visited, 0, sizeof(arr));

		cin >> m >> n >> K;
		for (int j = 0; j < K; j++) {
			int x, y;
			cin >> x >> y;
			arr[y][x] = 1;
		}

		int cnt = 0;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (!visited[j][k] && arr[j][k] == 1) {
					cnt++;
					floodfill(k, j);
				}
			}
		}

		cout << cnt << '\n';
	}

	return 0;
}