#include <bits/stdc++.h>
using namespace std;

int parent[100001];

int getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) return;
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

bool isUnion(int a, int b) {
	return getParent(a) == getParent(b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, q;
	cin >> n >> q;

	vector<pair<int, pair<int, int>>> logs;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		int x1, x2, y;
		cin >> x1 >> x2 >> y;
		logs.push_back({ x1, { x2, i } });
	}

	sort(logs.begin(), logs.end());

	int maxX = logs[0].second.first;
	int prevIdx = logs[0].second.second;

	for (int i = 1; i < n; i++) {
		int x1 = logs[i].first;
		int x2 = logs[i].second.first;
		int idx = logs[i].second.second;

		if (x1 <= maxX) {
			unionParent(prevIdx, idx);
			maxX = max(maxX, x2);
		}
		else {
			prevIdx = idx;
			maxX = x2;
		}
	}

	while (q--) {
		int a, b;
		cin >> a >> b;
		cout << isUnion(a, b) << '\n';
	}
	return 0;
}
