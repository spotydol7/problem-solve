import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int[][] dist = new int[N + 1][N + 1];
        int[][] origin = new int[N + 1][N + 1];

        for (int i = 1; i <= N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= N; j++) {
                dist[i][j] = Integer.parseInt(st.nextToken());
                origin[i][j] = dist[i][j];
            }
        }

        for (int m = 1; m <= N; m++) {
            for (int s = 1; s <= N; s++) {
                for (int e = 1; e <= N; e++) {
                    if (s == m || e == m || s == e) continue;

                    if (dist[s][e] == dist[s][m] + dist[m][e]) origin[s][e] = 0;

                    if (dist[s][e] > dist[s][m] + dist[m][e]) {
                        System.out.println(-1);
                        return;
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                ans += origin[i][j];
            }
        }

        System.out.println(ans / 2);
    }
}
