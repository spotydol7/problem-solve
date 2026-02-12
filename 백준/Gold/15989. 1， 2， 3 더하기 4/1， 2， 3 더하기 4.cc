#include <bits/stdc++.h>
using namespace std;

int dp[10001][4];

int main() {
	int T;
	cin >> T;

	dp[0][1] = 1;
	dp[1][1] = 1;

	for (int i = 2; i < 10001; i++) {
		dp[i][1] = dp[i - 1][1];
		dp[i][2] = dp[i - 1][1] + dp[i - 2][2];
		if (i >= 3) dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
	}

	while (T--) {
		int N;
		cin >> N;
		cout << dp[N][1] + dp[N][2] + dp[N][3] << '\n';
	}

	return 0;
}