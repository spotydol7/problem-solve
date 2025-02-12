#include <bits/stdc++.h>
using namespace std;

int n;
int ans = INT_MAX;
vector<int> popular;
vector<int> adjacent[11];
int visited[11];
int picked[11];

int calc(vector<int> &v1, vector<int> &v2) {
	int sum1 = 0;
	for (auto iter = v1.begin(); iter != v1.end(); iter++) {
		sum1 += popular[(*iter) - 1];
	}
	
	int sum2 = 0;
	for (auto iter = v2.begin(); iter != v2.end(); iter++) {
		sum2 += popular[(*iter) - 1];
	}

	return abs(sum1 - sum2);
}

bool check(int x, vector<int> &v) {
	// 지역구 다 연결돼있는지 확인
	if (v.size() == 1) return true;
	if (v.empty()) return false;

	memset(visited, 0, sizeof(visited));

	queue<int> q;
	q.push(x);
	visited[x] = 1;

	vector<bool> inRegion(n + 1, false); // 같은 지역구 내에서만 bfs 돌리려고 bool 벡터 사용
	for (int i = 0; i < v.size(); i++) {
		inRegion[v[i]] = true;
	}
	
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < adjacent[cur].size(); i++) {
			int next = adjacent[cur][i];
			if (!visited[next] && inRegion[next]) {
				q.push(next);
				visited[next] = 1;
			}
		}
	}

	for (int i = 0; i < v.size(); i++) {
		if (visited[v[i]] == 0) return false;
	}
	return true;
}

void pick(int idx, int level, int max_level) { // params: idx - dfs 시작 노드, level - dfs 깊이, max_level - dfs 최대 깊이
	if (level == max_level) {
		vector<int> region1;
		vector<int> region2;

		for (int i = 1; i <= n; i++) {
			if (picked[i]) region1.push_back(i);
			else region2.push_back(i);
		}

		if (check(region1[0], region1) && check(region2[0], region2)) { // 지역구 2개가 다 유효하면
			int temp = calc(region1, region2); // 계산
			ans = temp < ans ? temp : ans; // 최솟값 갱신
		}
	}
	else {
		for (int i = idx; i <= n; i++) { // 지역구 1에 넣을 거 고르기
			if (!picked[i]) {
				picked[i] = 1;
				pick(idx + 1, level + 1, max_level);
				picked[i] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		popular.push_back(temp);
	}

	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> temp;
			adjacent[i].push_back(temp); // 인접행렬
			adjacent[temp].push_back(i);
		}
	}

	for (int i = 1; i < n; i++) { // 지역구1 크기 1부터 n-1까지
		memset(picked, 0, sizeof(picked));
		pick(1, 0, i);
	}

	ans = ans == INT_MAX ? -1 : ans;
	cout << ans;

	return 0;
}