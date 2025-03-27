#include <bits/stdc++.h>
using namespace std;

int n;
int ans = -1;
int inDegree[10001];
int worktime[10001];
int dp[10001];
vector<int> graph[10001];
queue<int> q;

void topology_sort() {
	for (int i = 1; i <= n; i++) {
		dp[i] = worktime[i];
		if (inDegree[i] == 0)
			q.push(i);
	}

	for (int i = 0; i < n; i++) {
		if (q.empty()) return;

		int cur = q.front();
		q.pop();

		ans = max(ans, dp[cur]);

		for (int next : graph[cur]) {
			dp[next] = max(dp[next], (dp[cur] + worktime[next]));
			if (--inDegree[next] == 0) {
				q.push(next);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int cur = 1; cur <= n; cur++) {
		int t;
		cin >> t;
		worktime[cur] = t;

		int num;
		cin >> num;
		inDegree[cur] = num;

		for (int j = 0; j < num; j++) {
			int pre;
			cin >> pre;
			graph[pre].push_back(cur);
		}
	}

	topology_sort();

	cout << ans;

	return 0;
}