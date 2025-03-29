#include <bits/stdc++.h>
using namespace std;

int dp[1002][1002];

int main() {
	string a, b;
	cin >> a >> b;

	int max = 0;
	for (int i = 1; i <= a.length(); i++) {
		for (int j = 1; j <= b.length(); j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				if (max < dp[i][j]) max = dp[i][j];
			}
			else dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
		}
	}
	int len = dp[a.length()][b.length()];

	string ans = "";
	int i = a.length();
	int j = b.length();
	while (i != 0 && j != 0)
	{
		if (a[i - 1] == b[j - 1])
		{
			ans += a[i - 1];
			i--;
			j--;
		}
		else
		{
			if (dp[i][j] == dp[i - 1][j])
				i--;
			else if (dp[i][j] == dp[i][j - 1])
				j--;
		}
	}

	reverse(ans.begin(), ans.end());

	cout << len << '\n' << ans;

	return 0;
}