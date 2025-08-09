class Solution {
    public int solution(int m, int n, int[][] puddles) {
        
        int[][] dp = new int[n][m];
        dp[0][0] = 1;
        
        for (int i = 0; i < puddles.length; i++) {
            int waterX = puddles[i][0] - 1;
            int waterY = puddles[i][1] - 1;
            
            dp[waterY][waterX] = -1;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 && j == 0) || dp[i][j] == -1) continue;
                
                int top = (i == 0 || dp[i - 1][j] == -1) ? 0 : dp[i - 1][j];
                int left = (j == 0 || dp[i][j - 1] == -1) ? 0 : dp[i][j - 1];

                dp[i][j] = (top + left) % 1000000007;
            }
        }
        
        return dp[n - 1][m - 1];
    }
}