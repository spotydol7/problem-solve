#include <bits/stdc++.h>
using namespace std;

int triangle[501][501];
int dp[501][501];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> triangle[i][j];
		}
	}

	dp[0][0] = triangle[0][0];

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			if (j == 0) dp[i][j] = dp[i - 1][j] + triangle[i][j];
			else if (j == i) dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
			else {
				dp[i][j] = max(triangle[i][j] + dp[i - 1][j - 1], triangle[i][j] + dp[i - 1][j]);
			}
			ans = max(ans, dp[i][j]);
		}
	}

	cout << ans;

	return 0;
}