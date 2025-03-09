#include <bits/stdc++.h>
using namespace std;

int dp[1001][31];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T, W;
    cin >> T >> W;
    
    vector<int> seq;
    for (int i = 1; i <= T; i++){
        int temp;
        cin >> temp;
        seq.push_back(temp);
    }
    

    for (int i = 1; i <= T; i++){
        // 이동 안함 -> 걍 1번 나무에 있음 ㅇㅇ
        dp[i][0] = dp[i - 1][0] + (seq[i - 1] == 1 ? 1 : 0);
        
        for (int j = 1; j <= W; j++){
            // j가 짝수면 j번 이동 후 위치는 1번나무, 홀수면 2번
            int currentTree = (j % 2 == 0) ? 1 : 2;
            
            // i - 1초일 때 j번 이동한 경우와 j - 1번 이동한 경우 중 최댓값 선택
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + (seq[i - 1] == currentTree ? 1 : 0);
        }
    }
    
    // W번 이하 이동한 결과들 중에 최댓값
    int ans = 0;
    for (int j = 0; j <= W; j++){
        ans = max(ans, dp[T][j]);
    }
    cout << ans << "\n";
    
    return 0;
}
