#include <bits/stdc++.h>
using namespace std;

unordered_map<string, string> parent;
unordered_map<string, int> ans;

string getParent(string a) {
	if (parent[a] == a) return a;
	return parent[a] = getParent(parent[a]);
}

void unionParent(string a, string b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) return;

	parent[b] = a;

	ans[a] += ans[b];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		parent.clear();
		ans.clear();

		int f;
		cin >> f;
		for (int i = 0; i < f; i++) {
			string a, b;
			cin >> a >> b;
			if (parent.count(a) == 0) {
				parent[a] = a;
				ans[a] = 1;
			}
			if (parent.count(b) == 0) {
				parent[b] = b;
				ans[b] = 1;
			}

			unionParent(a, b);

			cout << ans[getParent(a)] << '\n';
		}
	}

	return 0;
}