#include <bits/stdc++.h>
using namespace std;

long long dp[1000001];

int main() {
	int n;
	cin >> n;

	dp[1] = 2;
	dp[2] = 7;
	long long sum = dp[1] + dp[2];

	for (int i = 3; i <= n; i++) {
		dp[i] = 2 * sum + dp[i - 2] + 2;
		sum += dp[i];
		dp[i] %= 1000000007;
		sum %= 1000000007;
	}

	cout << dp[n];
}