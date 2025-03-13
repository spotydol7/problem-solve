#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= m; j++) {
			dp[i][j] = str[j - 1] - '0';
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (dp[i][j]) { // 1인 경우
				dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
				ans = max(ans, dp[i][j]);
			}
		}
	}

	cout << ans * ans;

	return 0;
}