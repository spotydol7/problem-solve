#include <bits/stdc++.h>
using namespace std;

int n, m;
int dp[101];
int inDegree[101];

vector<pair<int, int>> adj[101];
vector<int> roots; // 기본 부품 
queue<int> q;

void topology_sort() {
	dp[n] = 1;
	
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) q.push(i);
	} // 이거 걍 q.push(n)으로 바꿔도 될듯

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (adj[cur].empty()) {
			roots.push_back(cur);
		}

		for (auto p : adj[cur]) {
			int next = p.first;
			int cost = p.second;
			dp[next] += dp[cur] * cost;
			if (--inDegree[next] == 0) q.push(next);
		}
	}

	sort(roots.begin(), roots.end());
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, z; // 중간 부품이나 완제품 X를 만드는데 중간 부품 혹은 기본 부품 Y가 K개 필요하다
		cin >> x >> y >> z;
		inDegree[y]++;
		adj[x].push_back({ y, z }); // x부터 드가자
	}

	topology_sort();

	for (int root : roots) {
		cout << root << ' ' << dp[root] << '\n';
	}

	return 0;
}