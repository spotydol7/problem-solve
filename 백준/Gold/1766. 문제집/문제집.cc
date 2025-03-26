#include <bits/stdc++.h>
using namespace std;

int n, m;
priority_queue<int, vector<int>, greater<int>> pq;
vector<int> adj[32002];
vector<int> ans;
int inDegree[32002];

void topology_sort() {
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) pq.push(i);
	}

	for (int i = 0; i < n; i++) {
		if (pq.empty()) return;

		int cur = pq.top();
		pq.pop();
		ans.push_back(cur);

		for (int next : adj[cur]) {
			if (--inDegree[next] == 0) {
				pq.push(next);
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		inDegree[v]++;
	}

	topology_sort();

	for (int num : ans) {
		cout << num << ' ';
	}

	return 0;
}