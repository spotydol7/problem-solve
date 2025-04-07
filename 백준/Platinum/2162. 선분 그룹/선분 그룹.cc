#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int, int>
using namespace std;

int parent[3001];
int sums[3001];

int findParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = findParent(parent[x]);
}

void uniParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a == b) return;
	parent[a] = b;
	sums[b] += sums[a];
}

int ccw(pii p1, pii p2, pii p3) {
	int s = p1.X * p2.Y + p2.X * p3.Y + p3.X * p1.Y;
	s -= (p1.X * p3.Y + p2.X * p1.Y + p3.X * p2.Y);

	if (s > 0) return 1;
	else if (s == 0) return 0;
	else return -1;
}

bool isIntersect(pair<pii, pii> l1, pair<pii, pii> l2) {
	pii p1 = l1.first;
	pii p2 = l1.second;
	pii p3 = l2.first;
	pii p4 = l2.second;

	int p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
	int p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

	if (p1p2 == 0 && p3p4 == 0) {
		if (p1 > p2) swap(p2, p1);
		if (p3 > p4) swap(p3, p4);

		return p3 <= p2 && p1 <= p4;
	}

	return p1p2 <= 0 && p3p4 <= 0;
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i <= n; i++) {
		parent[i] = i;
		sums[i] = 1;
	}

	vector<pair<pii, pii>> lines;
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		lines.push_back({ {x1, y1}, {x2, y2} });
	}

	for (int i = 0; i < lines.size(); i++) {
		for (int j = 0; j < lines.size(); j++) {
			if (i == j) continue;
			if (isIntersect(lines[i], lines[j])) {
				uniParent(i, j);
			}
		}
	}

	int max = -1;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (parent[i] == i) cnt++;
		if (sums[i] > max) max = sums[i];
	}

	cout << cnt << '\n' << max;

	return 0;
}