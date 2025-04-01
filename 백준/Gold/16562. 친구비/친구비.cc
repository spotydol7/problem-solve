#include <bits/stdc++.h>
using namespace std;

int parent[10001];
vector<pair<int, int>> cnt;
int friendFee[10001];

int getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
	if (a == b) return;
	a = getParent(a);
	b = getParent(b);
	if (friendFee[a] < friendFee[b]) parent[b] = a;
	else parent[a] = b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		cin >> friendFee[i];
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		unionParent(a, b);
	}

	unordered_set<int> roots;

	for (int i = 1; i <= n; i++) {
		roots.insert(getParent(i));
	}

	int total = 0;
	for (int root : roots) {
		total += friendFee[root];
	}

	if (total <= k) cout << total;
	else cout << "Oh no";

	return 0;
}