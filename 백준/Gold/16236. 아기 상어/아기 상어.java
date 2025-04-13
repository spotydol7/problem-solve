import java.io.*;
import java.util.*;

class Node implements Comparable<Node> {
    int r, c, dist;

    Node(int r, int c, int dist) {
        this.r = r;
        this.c = c;
        this.dist = dist;
    }

    @Override
    public int compareTo(Node o) {
        if (this.dist == o.dist) {
            if (this.r == o.r) return this.c - o.c;
            return this.r - o.r;
        }
        return this.dist - o.dist;
    }
}

public class Main {

    static int N;
    static int[][] board;
    static int[] dr = {-1, 0, 0, 1};
    static int[] dc = {0, -1, 1, 0};
    static int size = 2;
    static int eatCnt = 0;
    static int time = 0;
    static Node shark;

    public static Node bfs(Node start) {
        boolean[][] visited = new boolean[N][N];
        Queue<Node> q = new LinkedList<>();
        List<Node> fishes = new ArrayList<>();

        q.offer(new Node(start.r, start.c, 0));
        visited[start.r][start.c] = true;

        while (!q.isEmpty()) {
            Node cur = q.poll();
            for (int i = 0; i < 4; i++) {
                int nr = cur.r + dr[i];
                int nc = cur.c + dc[i];
                int ndist = cur.dist + 1;

                if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
                if (visited[nr][nc]) continue;

                int target = board[nr][nc];

                if (target <= size) {
                    visited[nr][nc] = true;
                    q.offer(new Node(nr, nc, ndist));
                    if (target != 0 && target < size) {
                        fishes.add(new Node(nr, nc, ndist));
                    }
                }
            }
        }

        if (fishes.isEmpty()) return null;

        Collections.sort(fishes);
        return fishes.get(0);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        board = new int[N][N];

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
                if (board[i][j] == 9) {
                    shark = new Node(i, j, 0);
                    board[i][j] = 0;
                }
            }
        }

        while (true) {
            Node target = bfs(shark);
            if (target == null) break;

            time += target.dist;
            shark = new Node(target.r, target.c, 0);
            board[target.r][target.c] = 0;
            eatCnt++;

            if (eatCnt == size) {
                size++;
                eatCnt = 0;
            }
        }

        System.out.println(time);
    }
}
