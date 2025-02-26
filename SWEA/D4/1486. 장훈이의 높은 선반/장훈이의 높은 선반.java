import java.io.*;
import java.util.*;

public class Solution {
    static int N, B;
    static int[] heights;
    static int best;
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        
        for (int t = 1; t <= T; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            B = Integer.parseInt(st.nextToken());
            heights = new int[N];
            
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < N; i++) {
                heights[i] = Integer.parseInt(st.nextToken());
            }
            
            best = Integer.MAX_VALUE;
            dfs(0, 0);
            System.out.println("#" + t + " " + (best - B));
        }
    }
    
    static void dfs(int idx, int sum) {
        if (sum >= B) {
            best = Math.min(best, sum);
            return;
        }
        if (idx == N) return;
        
        dfs(idx + 1, sum + heights[idx]);
        dfs(idx + 1, sum);
    }
}
