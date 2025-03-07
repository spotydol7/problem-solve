import java.io.*;
import java.util.*;

public class Solution {
    static int N, answer;
    static int[][] map;

    static int[] dx = {1, 1, -1, -1};
    static int[] dy = {1, -1, -1, 1};
    static boolean[] dessertVisited;
    static int startX, startY;

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        for(int tc = 1; tc <= T; tc++){
            N = Integer.parseInt(br.readLine());
            map = new int[N][N];
            for(int i = 0; i < N; i++){
                StringTokenizer st = new StringTokenizer(br.readLine(), " ");
                for(int j = 0; j < N; j++){
                    map[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            answer = -1;
            
            for(int i = 0; i < N - 2; i++){
                for(int j = 1; j < N - 1; j++){
                    dessertVisited = new boolean[101];
                    startX = i;
                    startY = j;
                    dessertVisited[map[i][j]] = true;
                    dfs(i, j, 0, 1);
                    dessertVisited[map[i][j]] = false;
                }
            }
            sb.append("#").append(tc).append(" ").append(answer).append("\n");
        }
        System.out.print(sb);
    }

    static void dfs(int x, int y, int dir, int count) {

        for(int d = dir; d < 4; d++){
            int nx = x + dx[d];
            int ny = y + dy[d];
            
            if(nx == startX && ny == startY && count >= 4){
                answer = Math.max(answer, count);
                return;
            }

            if(nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;

            if(dessertVisited[map[nx][ny]])
                continue;
            
            dessertVisited[map[nx][ny]] = true;
            dfs(nx, ny, d, count + 1);
            dessertVisited[map[nx][ny]] = false;
        }
    }
}
