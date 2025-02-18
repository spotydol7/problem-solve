#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	vector<int> rope;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		rope.push_back(temp);
	}

	sort(rope.begin(), rope.end());

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = rope[n - i] * i > ans ? rope[n - i] * i : ans;
	}

	cout << ans;

	return 0;
}