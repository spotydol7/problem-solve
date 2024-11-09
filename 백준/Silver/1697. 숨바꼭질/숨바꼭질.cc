#include <bits/stdc++.h>
using namespace std;

bool visited[100001];
int moves[] = { 1, -1, 0 };
int teleport[] = { 1, 1, 2 };
int cnt = 0;

int bfs(int start, int end) {
	queue<pair<int,int>> q;
	q.push(make_pair(start, cnt));
	visited[start] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int cur = q.front().second;
		q.pop();
		
		for (int i = 0; i < 3; i++) {
			int next = x + moves[i];
			next *= teleport[i];
			if (next == end) return cur + 1;
			if (next >= 0 && next <= 100000 && !visited[next]) {
				q.push(make_pair(next, cur + 1));
				visited[next] = true;
				cnt++;
			}
		}
		
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	if (n == k) cout << 0;
	else cout << bfs(n, k);

	return 0;
}