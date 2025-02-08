#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int n, m;
bool isLoop;
char arr[51][51];
int visited[51][51];
int dp[51][51];
int dr[] = { 1, -1, 0, 0 };
int dc[] = { 0, 0, 1, -1 };

int dfs(int r, int c) {
	if (visited[r][c]) {
		isLoop = true;
		return -1;
	}
	if (dp[r][c] != -1) return dp[r][c];

	int num;
	if (arr[r][c] > '0' && arr[r][c] <= '9') num = arr[r][c] - '0';

	visited[r][c] = 1;
	dp[r][c] = 0;

	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i] * num;
		int nc = c + dc[i] * num;

		if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
		if (arr[nr][nc] == 'H') continue;
		dp[r][c] = max(dp[r][c], dfs(nr, nc) + 1);
	}
	visited[r][c] = 0;

	return dp[r][c];
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		getchar();
		for (int j = 0; j < m; j++) {
			scanf("%1c", &arr[i][j]);
		}
	}

	int ans = dfs(0, 0);
	if (isLoop) printf("-1\n");
	else printf("%d\n", ans + 1);

	return 0;
}