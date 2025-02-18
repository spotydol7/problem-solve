#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	int ans = 0;
	for (int i = n - 2; i >= 0; i--) {
		if (v[i] >= v[i + 1]) {
			int d = v[i] - v[i + 1] + 1;
			v[i] -= d;
			ans += d;
		}
	}

	cout << ans;

	return 0;
}