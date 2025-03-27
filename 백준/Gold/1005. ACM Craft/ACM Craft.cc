#include <bits/stdc++.h>
using namespace std;

int n, k, w;
long long ans;
int inDegree[1001];
int buildTime[1001];
long long dp[1001];
vector<int> adj[1001];
queue<int> q;

void topology_sort() {
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) q.push(i);
		dp[i] = buildTime[i];
	}

	for (int i = 0; i < n; i++) {
		if (q.empty()) return;

		int cur = q.front();
		q.pop();

		for (int next : adj[cur]) {
			dp[next] = max(dp[next], dp[cur] + buildTime[next]);
			if (--inDegree[next] == 0)
				q.push(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		memset(buildTime, 0, sizeof(buildTime));
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < 1001; i++) adj[i].clear();

		cin >> n >> k;

		for (int i = 1; i <= n; i++) {
			int temp;
			cin >> temp;
			buildTime[i] = temp;
		}

		for (int i = 0; i < k; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			inDegree[v]++;
		}

		cin >> w;
		
		topology_sort();

		cout << dp[w] << '\n';
	}

	return 0;
}