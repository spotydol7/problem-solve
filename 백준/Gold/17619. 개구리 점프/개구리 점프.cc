#include<bits/stdc++.h>
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
	parent[a] = b;
}

bool isUnion(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) return true;
	return false;
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

	for (int i = 0; i < n - 1; i++) {
		if (logs[i].second.first >= logs[i + 1].first) {
			unionParent(logs[i].second.second, logs[i + 1].second.second);
		}
	}

	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		if (isUnion(a, b)) cout << 1 << '\n';
		else cout << 0 << '\n';
	}

	return 0;
}