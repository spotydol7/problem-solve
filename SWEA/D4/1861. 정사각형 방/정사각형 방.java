import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
    static int[][] room;
    static int[] dr = {1, -1, 0, 0};
    static int[] dc = {0, 0, 1, -1};
    static int n;
    static int maxDepth;
    static int maxNum;

    public static int dfs(int r, int c, int depth) {
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
            if (room[nr][nc] != room[r][c] + 1) continue;

            depth = dfs(nr, nc, depth + 1);

            if (depth > maxDepth) {
                maxDepth = depth;
                maxNum = room[r][c];
            }
            else if (maxDepth == depth && maxNum > room[r][c]) maxNum = room[r][c];
            break;
        }
        return depth;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for (int test_case = 1; test_case <= T; test_case++) {
            n = Integer.parseInt(br.readLine());

            room = new int[n + 1][n + 1];

            for (int i = 0; i < n; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for (int j = 0; j < n; j++) {
                    room[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            maxDepth = 0;
            maxNum = 0;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dfs(i, j, 1);
                }
            }
            System.out.println("#" + test_case + " " + maxNum + " " + maxDepth);
        }
    }
}
