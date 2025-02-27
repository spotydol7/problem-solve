#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> coins(n);
    long long total = 0;
    for (int i = 0; i < n; i++){
        cin >> coins[i];
        total += coins[i];
    }
    
    vector<int> dp(n);
    for (int i = 0; i < n; i++){
        dp[i] = coins[i];
    }
    
    for (int len = 1; len < n; len++){
        for (int i = 0; i < n - len; i++){
            int j = i + len;
            dp[i] = max(coins[i] - dp[i + 1], coins[j] - dp[i]);
        }
    }
    
    cout << (total + dp[0]) / 2 << "\n";
    
    return 0;
}
