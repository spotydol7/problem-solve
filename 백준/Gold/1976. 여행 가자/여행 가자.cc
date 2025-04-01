#include <bits/stdc++.h>
using namespace std;

int parent[201];

int getParent(int n) {
	if (parent[n] == n) return n;
	return parent[n] = getParent(parent[n]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

bool isUnion(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int cmd;
			cin >> cmd;
			if (cmd) {
				unionParent(i, j);
			}
		}
	}

	int a;
	cin >> a;
	for (int i = 0; i < m - 1; i++) {
		int b;
		cin >> b;
		if (!isUnion(a, b)) {
			cout << "NO";
			return 0;
		}
	}

	cout << "YES";

	return 0;
}