#include <bits/stdc++.h>
using namespace std;

int parent[1000001];

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

	for (int i = 0; i < m; i++) {
		int cmd, a, b;
		cin >> cmd >> a >> b;

		if (!cmd) {
			// a 집합과 b 집합 합침
			unionParent(a, b);
		}
		else if (cmd) {
			// a와 b가 같은 집합인지 확인
			if (isUnion(a, b)) cout << "YES\n";
			else cout << "NO\n";
		}
	}

	return 0;
}