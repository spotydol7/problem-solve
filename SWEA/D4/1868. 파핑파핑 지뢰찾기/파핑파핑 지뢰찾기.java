import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Solution {
    static int N;
    static char[][] board;
    static boolean[][] visited;

    static int[] dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int[] dy = {-1, 0, 1, -1, 1, -1, 0, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        for (int t = 1; t <= T; t++) {
            N = Integer.parseInt(br.readLine());
            board = new char[N][N];
            for (int i = 0; i < N; i++) {
                board[i] = br.readLine().toCharArray();
            }
            
            int[][] adj = new int[N][N];
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (board[i][j] == '*') {
                        adj[i][j] = -1;
                    } else {
                        int count = 0;
                        for (int k = 0; k < 8; k++) {
                            int ni = i + dx[k];
                            int nj = j + dy[k];
                            if (ni >= 0 && ni < N && nj >= 0 && nj < N && board[ni][nj] == '*') {
                                count++;
                            }
                        }
                        adj[i][j] = count;
                    }
                }
            }
            
            visited = new boolean[N][N];
            int clicks = 0;
            
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (adj[i][j] == 0 && !visited[i][j]) {
                        clicks++;
                        dfs(i, j, adj);
                    }
                }
            }
            
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (adj[i][j] != -1 && !visited[i][j]) {
                        clicks++;
                    }
                }
            }
            
            System.out.println("#" + t + " " + clicks);
        }
    }
    
    static void dfs(int x, int y, int[][] adj) {
        if (visited[x][y]) return;
        visited[x][y] = true;
        
        if (adj[x][y] == 0) {
            for (int k = 0; k < 8; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny] && adj[nx][ny] != -1) {
                    dfs(nx, ny, adj);
                }
            }
        }
    }
}
