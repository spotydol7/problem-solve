#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(3));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> cost[i][j];
        }
    }

    int ans = 1e9;

    for(int k = 0; k < 3; k++) {
        vector<vector<int>> dp(n, vector<int>(3, 1e9));
        for(int i = 0; i < 3; i++) {
            if(i == k) dp[0][i] = cost[0][i];
        }

        for(int i = 1; i < n; i++) {
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];
        }

        for(int i = 0; i < 3; i++) {
            if(i == k) continue;
            ans = min(ans, dp[n-1][i]);
        }
    }

    cout << ans << '\n';

    return 0;
}