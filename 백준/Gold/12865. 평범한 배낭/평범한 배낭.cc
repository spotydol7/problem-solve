#include <bits/stdc++.h>
using namespace std;

int dp[101][100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<pair<int, int>> items;
	items.push_back({ -1, -1 }); // 1-based 인덱스 할라고 쓰레기값 하나 넣음
	for (int i = 0; i < n; i++) {
		int w, v;
		cin >> w >> v;
		items.push_back({ w, v });
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			int curW = items[i].first;
			int curV = items[i].second;

			if (curW > j) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - curW] + curV);
			}
		}
	}

	cout << dp[n][k];

	return 0;
}