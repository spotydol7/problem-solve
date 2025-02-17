#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		vector<int> v;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			v.push_back(temp);
		}

		long long ans = 0;
		int maximum = 0;
		for (int i = v.size() - 1; i >= 0; i--) {
			if (v[i] >= maximum) maximum = v[i];
			else ans += (maximum - v[i]);
		}
		cout << ans << '\n';
	}
	return 0;
}