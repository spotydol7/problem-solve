#include <bits/stdc++.h>
using namespace std;

int sum[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	vector<int> man;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		man.push_back(temp);
	}

	sort(man.begin(), man.end());
	
	sum[0] = man[0];
	for (int i = 1; i < n; i++) {
		sum[i] = sum[i - 1] + man[i];
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += sum[i];
	}

	cout << ans << '\n';

	return 0;
}