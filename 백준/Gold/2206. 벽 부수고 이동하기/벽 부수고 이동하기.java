import java.io.*;
import java.util.*;

class Node2 {
    int r, c, wall, dist;

    Node2(int r, int c, int wall, int dist) {
        this.r = r;
        this.c = c;
        this.wall = wall;
        this.dist = dist;
    }
}

public class Main {
    static int n, m;
    static int[][] board;
    static boolean[][][] visited;
    static int[] dr = {1, -1, 0, 0};
    static int[] dc = {0, 0, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        board = new int[n][m];
        visited = new boolean[n][m][2];

        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            for (int j = 0; j < m; j++) {
                board[i][j] = str.charAt(j) - '0';
            }
        }

        System.out.println(bfs(0, 0));
    }

    public static int bfs(int r, int c) {
        Queue<Node2> q = new LinkedList<>();
        q.offer(new Node2(r, c, 0, 1));
        visited[r][c][0] = true;

        while (!q.isEmpty()) {
            Node2 cur = q.poll();

            if (cur.r == n - 1 && cur.c == m - 1) {
                return cur.dist;
            }

            for (int i = 0; i < 4; i++) {
                int nr = cur.r + dr[i];
                int nc = cur.c + dc[i];


                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;


                if (board[nr][nc] == 0 && !visited[nr][nc][cur.wall]) {
                    visited[nr][nc][cur.wall] = true;
                    q.offer(new Node2(nr, nc, cur.wall, cur.dist + 1));
                }

                if (board[nr][nc] == 1 && cur.wall == 0 && !visited[nr][nc][1]) {
                    visited[nr][nc][1] = true;
                    q.offer(new Node2(nr, nc, 1, cur.dist + 1));
                }
            }
        }
        return -1;
    }
}
