#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	unordered_set<string> us;
	set<string> st;
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		us.insert(temp);
	}

	for (int i = 0; i < m; i++) {
		string temp;
		cin >> temp;
		if (us.count(temp)) st.insert(temp);
	}

	cout << st.size() << '\n';
	for (auto iter = st.begin(); iter != st.end(); iter++) {
		cout << *iter << '\n';
	}
	return 0;
}