import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static final int INF = 987654321;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int V = Integer.parseInt(st.nextToken());
        int E = Integer.parseInt(st.nextToken());
        int[][] dist = new int[V + 1][V + 1];

        for (int i = 0; i <= V; i++) {
            for (int j = 0; j <= V; j++) {
                if (i != j) dist[i][j] = INF;
            }
        }

        for (int i = 0; i < E; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            dist[u][v] = Math.min(dist[u][v], w);
        }

        for (int m = 1; m <= V; m++) {
            for (int s = 1; s <= V; s++) {
                for (int e = 1; e <= V; e++) {
                    if (dist[s][e] > dist[s][m] + dist[m][e])
                        dist[s][e] = dist[s][m] + dist[m][e];
                }
            }
        }

        int min = INF;
        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++) {
                if (i == j) continue;
                min = Math.min(min, dist[i][j] + dist[j][i]);
            }
        }
        if (min == INF) min = -1;
        System.out.println(min);
    }
}
