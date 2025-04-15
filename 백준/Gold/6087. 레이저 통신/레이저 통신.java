import java.io.*;
import java.util.*;

class Node {
    int r, c, dir, curve;
    Node(int r, int c, int dir, int curve) {
        this.r = r;
        this.c = c;
        this.dir = dir;
        this.curve = curve;
    }
}

public class Main {
    static int W, H;
    static char[][] board;
    static int[] dr = {-1, 1, 0, 0};
    static int[] dc = {0, 0, -1, 1};
    static int INF = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        W = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());
        board = new char[H][W];

        List<int[]> points = new ArrayList<>();
        for (int i = 0; i < H; i++) {
            String line = br.readLine();
            for (int j = 0; j < W; j++) {
                board[i][j] = line.charAt(j);
                if (board[i][j] == 'C') points.add(new int[]{i, j});
            }
        }

        int ans = bfs(points.get(0), points.get(1));
        System.out.println(ans);
    }

    static int bfs(int[] start, int[] end) {
        int[][][] dist = new int[H][W][4];
        for (int[][] row : dist)
            for (int[] col : row)
                Arrays.fill(col, INF);

        Queue<Node> q = new LinkedList<>();

        for (int d = 0; d < 4; d++) {
            dist[start[0]][start[1]][d] = 0;
            q.add(new Node(start[0], start[1], d, 0));
        }

        while (!q.isEmpty()) {
            Node cur = q.poll();

            for (int d = 0; d < 4; d++) {
                int nr = cur.r + dr[d];
                int nc = cur.c + dc[d];

                if (nr < 0 || nr >= H || nc < 0 || nc >= W) continue;
                if (board[nr][nc] == '*') continue;

                int nextCurve = cur.curve + (cur.dir != d ? 1 : 0);

                if (dist[nr][nc][d] > nextCurve) {
                    dist[nr][nc][d] = nextCurve;
                    q.add(new Node(nr, nc, d, nextCurve));
                }
            }
        }

        int min = INF;
        for (int d = 0; d < 4; d++) {
            min = Math.min(min, dist[end[0]][end[1]][d]);
        }

        return min;
    }
}
