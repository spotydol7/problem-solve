#include <bits/stdc++.h>
using namespace std;

int parent[1000001];
int sums[1000001];

int getParent(int x) {
	if (parent[x] == x) return x;
	
	if (parent[x] == 0) {
		parent[x] = x;
		sums[x] = 1;
	}

	return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) return;
	parent[b] = a;
	sums[a] += sums[b];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		char cmd;
		cin >> cmd;
		if (cmd == 'I') {
			int a, b;
			cin >> a >> b;
			unionParent(a, b);
		}
		else if (cmd == 'Q') {
			int a;
			cin >> a;
			cout << sums[getParent(a)] << '\n';
		}
	}

	return 0;
}