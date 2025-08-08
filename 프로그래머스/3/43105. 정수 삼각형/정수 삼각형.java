import java.util.*;

class Solution {
    public int solution(int[][] triangle) {
        int h = triangle.length;
        
        for (int i = h - 1; i > 0; i--) {
            for (int j = 0; j < triangle[i].length - 1; j++) {
                int max = Math.max(triangle[i][j], triangle[i][j + 1]);
                triangle[i - 1][j] = triangle[i - 1][j] + max;
            }
        }
        
        return triangle[0][0];
    }
}