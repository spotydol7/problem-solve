#include <bits/stdc++.h>
using namespace std;

int parent[1000001];

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
	cin.tie(0);
	cout.tie(0);

	int T, n, m, k;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		memset(parent, 0, sizeof(parent));

		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
		}

		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			unionParent(a, b);
		}

		cin >> m;
		cout << "Scenario " << test_case << ':' << '\n';
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			if (isUnion(a, b)) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		cout << '\n';
	}

	return 0;
}