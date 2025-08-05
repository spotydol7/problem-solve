
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Node {
    int h;
    int w;

    Node(int h, int w) {
        this.h = h;
        this.w = w;
    }
}

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int w = Integer.parseInt(st.nextToken());
            int h = Integer.parseInt(st.nextToken());
            if (w == 0 && h == 0) break;

            int[][] board = new int[h][w];
            boolean[][] visited = new boolean[h][w];

            for (int i = 0; i < h; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < w; j++) {
                    board[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            int[] dw = {1, -1, 0, 0, 1, 1, -1, -1};
            int[] dh = {0, 0, 1, -1, 1, -1, 1, -1};

            Queue<Node> q = new LinkedList<>();
            int ans = 0;

            // BFS
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (board[i][j] == 1 && !visited[i][j]) {
                        q.add(new Node(i, j));
                        visited[i][j] = true;

                        while(!q.isEmpty()) {
                            Node cur = q.poll();
                            for (int dir = 0; dir < 8; dir++) {
                                int nh = cur.h + dh[dir];
                                int nw = cur.w + dw[dir];

                                if (nh >= 0 && nh < h && nw >= 0 && nw < w) {
                                    if (board[nh][nw] == 1 && !visited[nh][nw]) {
                                        visited[nh][nw] = true;
                                        q.add(new Node(nh, nw));
                                    }
                                }
                            }
                        }

                        ans++;
                    }
                }
            }

            System.out.println(ans);
        }
    }
}