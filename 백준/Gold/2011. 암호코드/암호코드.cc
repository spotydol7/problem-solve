#include<bits/stdc++.h>
using namespace std;

long long dp[5001];

int main() {
	string str;
	cin >> str;
	
	if (str[0] == '0') {
		cout << 0;
		return 0;
	}

	dp[0] = 1;
	dp[1] = 1;
	
	for (int i = 2; i <= str.length(); i++) {
		if (str[i - 1] != '0') dp[i] = dp[i - 1] % 1000000;

		int alpha = (str[i - 1] - '0') + 10 * (str[i - 2] - '0');
		if (alpha >= 10 && alpha <= 26) {
			dp[i] = (dp[i] + dp[i - 2]) % 1000000;
		}
	}

	cout << dp[str.length()];

	return 0;
}