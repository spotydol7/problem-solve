import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
    static final int INF = 987654321;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());

        int[][] dist = new int[N + 1][N + 1];

        ArrayList<Integer>[][] via = new ArrayList[N + 1][N + 1]; // 경유지 ㅅㅂ 자바초기화좃같노
        for (int i = 0; i <= N; i++)
            for (int j = 0; j <= N; j++) {
                via[i][j] = new ArrayList<>();
            }

        for (int i = 0; i <= N; i++)
            for (int j = 0; j <= N; j++)
                if (i != j) dist[i][j] = INF;

        for (int i = 0; i < M; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            dist[u][v] = Math.min(dist[u][v], w);
        }

        for (int m = 1; m <= N; m++) {
            for (int s = 1; s <= N; s++) {
                for (int e = 1; e <= N; e++) {
                    if (dist[s][e] > dist[s][m] + dist[m][e]) {
                        dist[s][e] = dist[s][m] + dist[m][e];

                        via[s][e].clear();
                        for (int node : via[s][m]) {
                            via[s][e].add(node);
                        }
                        via[s][e].add(m);
                        for (int node : via[m][e]) {
                            via[s][e].add(node);
                        }
                    }
                }
            }
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (dist[i][j] == INF) dist[i][j] = 0;
                sb.append(dist[i][j] + " ");
            }
            sb.append('\n');
        }

        for (int i = 1; i <= N; i++) { // 자바는 출력도 좃같노
            for (int j = 1; j <= N; j++) {
                if (dist[i][j] == 0) {
                    sb.append(0 + "\n");
                    continue;
                }
                sb.append(via[i][j].size() + 2 + " ");
                sb.append(i + " ");
                for (int node : via[i][j]) {
                    sb.append(node + " ");
                }
                sb.append(j + "\n");
            }
        }

        System.out.println(sb);
    }
}
