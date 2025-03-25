#include <bits/stdc++.h>
using namespace std;

int n, m;
int inDegree[32001]; // 진입차수 저장
vector<int> graph[32001];
vector<int> ans;
queue<int> q;


void topology_sort() {
	for (int i = 1; i <= n; i++) 
		if (inDegree[i] == 0) q.push(i);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		ans.push_back(cur);

		for (int next : graph[cur]) {
			inDegree[next]--;
			if (inDegree[next] == 0) q.push(next);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		// 이는 학생 A가 학생 B의 앞에 서야 한다는 의미이다.
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		inDegree[v]++;
	}

	topology_sort();

	for (auto iter = ans.begin(); iter != ans.end(); iter++) {
		cout << *iter << ' ';
	}

	return 0;
}