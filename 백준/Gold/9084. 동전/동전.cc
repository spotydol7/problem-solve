#include <bits/stdc++.h>
using namespace std;

int coins[21];
int dp[10001];

int main() {
	int T;
	cin >> T;
	while (T--) {
		memset(coins, 0, sizeof(coins));
		memset(dp, 0, sizeof(dp));

		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> coins[i];
		}

		int m;
		cin >> m;
		
		dp[0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = coins[i]; j <= m; j++) {
				dp[j] += dp[j - coins[i]];
			}
		}

		cout << dp[m] << '\n';
	}

	return 0;
}