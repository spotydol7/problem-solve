#include <bits/stdc++.h>
using namespace std;

int parent[100001];

int findParent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = findParent(parent[x]);
}

void uniParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a == b) return;
	parent[a] = b;
}

int main() {
	int g, p;
	cin >> g >> p;
	
	// i번째 비행기를 1번부터 gi (1 ≤ gi ≤ G) 번째 게이트중 하나에 영구적으로 도킹
	vector<int> gis;
	for (int i = 0; i < p; i++) {
		int temp;
		cin >> temp;
		gis.push_back(temp);
	}

	for (int i = 1; i <= g; i++) {
		parent[i] = i;
	}

	int ans = 0;
	for (int i = 0; i < gis.size(); i++) {
		if (findParent(gis[i]) == 0) break;
		else {
			parent[findParent(gis[i])] = findParent(findParent(gis[i]) - 1); // 게이트의 부모를 하나 낮은 게이트의 부모로 연결
			ans++;
		}
	}

	cout << ans;

	return 0;
}