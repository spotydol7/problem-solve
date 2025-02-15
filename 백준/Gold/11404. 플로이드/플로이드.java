import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static int n, m;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        n = Integer.parseInt(br.readLine());
        m = Integer.parseInt(br.readLine());
        int[][] road = new int[n + 1][n + 1];

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i != j) road[i][j] = 987654321;
            }
        }

        for (int i = 0; i < m; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            road[u][v] = Math.min(road[u][v], w);
        }

        for (int m = 1; m <= n; m++) {
            for (int s = 1; s <= n; s++) {
                for (int e = 1; e <= n; e++) {
                    if (road[s][e] > road[s][m] + road[m][e]) {
                        road[s][e] = road[s][m] + road[m][e];
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (road[i][j] == 987654321) road[i][j] = 0;
                sb.append(road[i][j] + " ");
            }
            sb.append("\n");
        }

        System.out.println(sb);
        br.close();
    }
}
