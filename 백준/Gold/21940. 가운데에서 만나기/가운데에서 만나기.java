import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
    static final int INF = 987654321;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int dist[][] = new int[N + 1][N + 1];
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= N; j++) {
                if (i != j) dist[i][j] = INF;
            }
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            dist[u][v] = Math.min(dist[u][v], w);
        }

        int K = Integer.parseInt(br.readLine());
        int[] friends = new int[K];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < K; i++) {
            friends[i] = Integer.parseInt(st.nextToken());
        }

        for (int m = 1; m <= N; m++) {
            for (int s = 1; s <= N; s++) {
                for (int e = 1; e <= N; e++) {
                    if (dist[s][e] > dist[s][m] + dist[m][e])
                        dist[s][e] = dist[s][m] + dist[m][e];
                }
            }
        }

        int[] maximum = new int[N + 1];
        int minimum = INF;
        for (int i = 1; i <= N; i++) {
            for (int city : friends) {
                maximum[i] = Math.max(maximum[i], dist[city][i] + dist[i][city]);
            }
            minimum = Math.min(minimum, maximum[i]);
        }

        ArrayList<Integer> ans = new ArrayList<>();
        for (int i = 1; i <= N; i++) {
            if (minimum >= maximum[i]) ans.add(i);
        }

        Collections.sort(ans);

        for (int a : ans) {
            System.out.print(a + " ");
        }
    }
}
