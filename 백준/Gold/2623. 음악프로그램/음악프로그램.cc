#include <bits/stdc++.h>
using namespace std;

int n, m;
int inDegree[1001];
vector<int> graph[1001];
vector<int> ans;
queue<int> q;

bool topology_sort() {
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) q.push(i);
	}

	for (int i = 0; i < n; i++) {
		if (q.empty()) return 0;

		int cur = q.front();
		q.pop();
		ans.push_back(cur);

		for (int next : graph[cur]) {
			if (--inDegree[next] == 0) q.push(next);
		}
	}
	return 1;
}

int main() {
	int pre;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		pre = -1;
		int num;
		cin >> num;
		for (int j = 0; j < num; j++) {
			int temp;
			cin >> temp;
			if (pre != -1) {
				graph[pre].push_back(temp);
				inDegree[temp]++;
			}
			pre = temp;
		}
	}

	if (topology_sort()) {
		for (int n : ans) {
			cout << n << '\n';
		}
	}
	else cout << 0;

	return 0;
}