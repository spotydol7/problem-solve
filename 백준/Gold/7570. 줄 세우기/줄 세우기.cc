#include<bits/stdc++.h>
using namespace std;
 
int dp[1000001];
 
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0);

    int n;
    
    int ans = -1;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
 
        dp[temp] = dp[temp - 1] + 1;
        ans = max(ans, dp[temp]);
    }
 
    cout << n - ans;
}