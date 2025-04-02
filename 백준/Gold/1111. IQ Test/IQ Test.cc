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

	int a, b, ans;

	if (n == 1 || (n == 2 && v[0] != v[1])) {
		cout << "A";
		return 0;
	}

	if (v[1] - v[0] != 0) 
		a = (v[2] - v[1]) / (v[1] - v[0]);

	b = v[1] - v[0] * a;

	for (int i = 1; i < v.size(); i++) {
		if (v[i] != v[i - 1] * a + b) {
			cout << "B";
			return 0;
		}
	}

	ans = v[n - 1] * a + b;
	cout << ans;

	return 0;
}