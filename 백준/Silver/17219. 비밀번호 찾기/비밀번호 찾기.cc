#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	string com, pw;
	map<string, string> mp;
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> com >> pw;
		mp.insert({ com, pw });
	}
	for (int i = 0; i < m; i++) {
		cin >> com;
		cout << mp[com] << '\n';
	}

	return 0;
}