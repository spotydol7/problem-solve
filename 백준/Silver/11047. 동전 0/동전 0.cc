#include <bits/stdc++.h>
using namespace std;

int coin[11];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	int cnt = 0;
	int sum = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (coin[i] <= k - sum) {
			cnt += ((k - sum) / coin[i]);
			sum += coin[i] * ((k - sum) / coin[i]);
		}
		if (sum == k) break;
	}

	cout << cnt << '\n';
	return 0;
}