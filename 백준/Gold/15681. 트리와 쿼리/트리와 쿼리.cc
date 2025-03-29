#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
bool visited[100001];
int cnt[100001];

int dfs(int n) {
	if (cnt[n] != 0) return cnt[n];
	visited[n] = true;
	int ret = 1;
	for (int i = 0; i < adj[n].size(); i++) {
		int next = adj[n][i];
		if (visited[next]) continue;
		ret += dfs(next);
	}
	cnt[n] = ret;
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, r, q;
	cin >> n >> r >> q;

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	cnt[r] = dfs(r);

	for (int i = 0; i < q; i++) {
		int query;
		cin >> query;

		cout << cnt[query] << '\n';
	}

	return 0;
}