#include <bits/stdc++.h>
using namespace std;

int n, m;
int adjacent[101][101];
int visited[101];

void dfs(int v) {
	visited[v] = 1;

	for (int i = 1; i <= n; i++) {
		if (adjacent[v][i] == 1 && visited[i] == 0) {
			dfs(i);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adjacent[a][b] = 1;
		adjacent[b][a] = 1;
	}

	dfs(1);

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += visited[i];
	}

	cout << ans - 1 << '\n';

	return 0;
}