#include <bits/stdc++.h>
using namespace std;

int parent[1000001];

int getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

void uniParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) return;
	parent[b] = a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	if (m == 0) {
		cout << n;
		return 0;
	}

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	vector<pair<int, int>> walls(m);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		walls[i] = { x, y };
	}

	sort(walls.begin(), walls.end());

	int currL = walls[0].first;
	int currR = walls[0].second;

	for (int i = 1; i < m; i++) {
		int nextL = walls[i].first;
		int nextR = walls[i].second;

		if (currR >= nextL) {
			currR = max(currR, nextR);
		}
		else {
			// 이전 구간 union
			for (int j = currL; j < currR; j++) {
				uniParent(j, j + 1);
			}
			currL = nextL;
			currR = nextR;
		}
	}

	for (int j = currL; j < currR; j++) {
		uniParent(j, j + 1);
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (getParent(i) == i) cnt++;
	}

	cout << cnt;
	return 0;
}
