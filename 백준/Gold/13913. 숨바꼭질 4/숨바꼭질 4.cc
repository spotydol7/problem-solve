#include <bits/stdc++.h>
using namespace std;

int N, K;
int dist[100001];
int parent[100001];

int main() {
	cin >> N >> K;

	if (N == K) {
		cout << 0 << '\n' << N << '\n';
		return 0;
	}
	
	memset(dist, -1, sizeof(dist));
	dist[N] = 0;
	queue<int> q;
	q.push(N);

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (cur == K) break;
		
		for (int next : { cur + 1, cur - 1, cur * 2 }) {
			if (next < 0 || next > 100000) continue;
			if (dist[next] != -1) continue;
			
			parent[next] = cur;
			dist[next] = dist[cur] + 1;
			q.push(next);
		}
	}

	vector<int> path;
	for (int v = K; v != -1; v = parent[v]) {
		path.push_back(v);
		if (v == N) break;
	}
	reverse(path.begin(), path.end());

	cout << dist[K] << '\n';
	for (int v : path) {
		cout << v << ' ';
	}

	return 0;
}