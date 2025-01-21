import javax.swing.*;
import java.awt.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    public static char[][] map;
    public static boolean[][] visited;
    static int n, m;
    static int curX, curY;
    static int cnt;

    static class point {
        int x;
        int y;

        public point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        map = new char[n + 1][m + 1];
        visited = new boolean[n + 1][m + 1];

        for (int i = 0; i < n; i++) {
            String line = bf.readLine();
            for (int j = 0; j < m; j++) {
                map[i][j] = line.charAt(j);
                if (map[i][j] == 'I') {
                    curX = i;
                    curY = j;
                }
            }
        }
        
        BFS(curX, curY);

        if (cnt == 0) System.out.println("TT");
        else System.out.println(cnt);
    }

    static void BFS(int x, int y) {
        Queue<Point> q = new LinkedList<>();
        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, 1, -1};

        q.add(new Point(x, y));
        visited[x][y] = true;

        while (!q.isEmpty()) {
            Point cur = q.poll();
            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                
                if (nx >= n || nx < 0 || ny >= m || ny < 0 || visited[nx][ny] || map[nx][ny] == 'X')
                    continue;

                if (map[nx][ny] == 'P') {
                    cnt++;
                }
                visited[nx][ny] = true;
                q.add(new Point(nx, ny));
            }
        }
    }
}
