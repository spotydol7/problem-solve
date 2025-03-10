#include <bits/stdc++.h>
using namespace std;

int dp[10001];
int coins[101];

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}

	//sort(coins, coins + n);
	
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = coins[i]; j <= k; j++) {
			dp[j] += dp[j - coins[i]];
		}
	}

	cout << dp[k];

	return 0;
}