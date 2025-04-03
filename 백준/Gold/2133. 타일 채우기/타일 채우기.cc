#include <bits/stdc++.h>
using namespace std;

int dp[31];

int main() {
	int n;
	cin >> n;

	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;

	for (int i = 4; i <= n; i++) {
		if (i % 2 == 1) dp[i] = 0;
		else {
			dp[i] = dp[2] * dp[i - 2];
			for (int j = 4; i - j >= 0; j += 2) {
				dp[i] += 2 * dp[i - j];
			}
		}
	}

	cout << dp[n];

	return 0;
}