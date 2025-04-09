import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int N, K, ans = Integer.MAX_VALUE;
    static int[][] dist;
    static boolean[] visited;
    static int[] planet;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        dist = new int[N + 1][N + 1];
        visited = new boolean[N + 1];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                dist[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int m = 0; m < N; m++) {
            for (int s = 0; s < N; s++) {
                for (int e = 0; e < N; e++) {
                    if (dist[s][e] > dist[s][m] + dist[m][e])
                        dist[s][e] = dist[s][m] + dist[m][e];
                }
            }
        }

        visited[K] = true;
        backtracking(1, K, 0);
        System.out.println(ans);
    }

    public static void backtracking(int depth, int start, int sum) {
        if (depth == N) {
            ans = Math.min(ans, sum);
            return;
        }
        for (int i = 0; i < N; i++) {
            if (i == start) continue;

            if (!visited[i]) {
                visited[i] = true;
                backtracking(depth + 1, i, sum + dist[start][i]);
                visited[i] = false;
            }
        }
    }
}
