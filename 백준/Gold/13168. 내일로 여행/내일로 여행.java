import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
    static final int INF = 987654321;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int R = Integer.parseInt(st.nextToken());

        double[][] dist = new double[N + 1][N + 1];
        double[][] dist2 = new double[N + 1][N + 1];

        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= N; j++) {
                if (i != j) {
                    dist[i][j] = INF;
                    dist2[i][j] = INF;
                }
            }
        }

        HashMap<String, Integer> cities = new HashMap<>();

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            String temp = st.nextToken();
            cities.putIfAbsent(temp, i);
        }

        int M = Integer.parseInt(br.readLine());
        String[] travel = new String[M + 1];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < M; i++) {
            travel[i] = st.nextToken();
        }

        int K = Integer.parseInt(br.readLine());
        for (int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());
            String train = st.nextToken();
            int start = cities.get(st.nextToken());
            int end = cities.get(st.nextToken());
            double cost = Integer.parseInt(st.nextToken());

            dist[start][end] = Math.min(dist[start][end], cost);
            dist[end][start] = Math.min(dist[end][start], cost);

            if (train.equals("Mugunghwa") || train.equals("ITX-Saemaeul") || train.equals("ITX-Cheongchun")) {
                dist2[start][end] = 0;
                dist2[end][start] = 0;
            } else if (train.equals("S-Train") || train.equals("V-Train")) {
                dist2[start][end] = Math.min(dist2[start][end], cost / 2.0);
                dist2[end][start] = Math.min(dist2[end][start], cost / 2.0);
            } else {
                dist2[start][end] = Math.min(dist2[start][end], cost);
                dist2[end][start] = Math.min(dist2[end][start], cost);
            }
        }

        for (int m = 1; m <= N; m++) {
            for (int s = 1; s <= N; s++) {
                for (int e = 1; e <= N; e++) {
                    if (dist[s][e] > dist[s][m] + dist[m][e]) {
                        dist[s][e] = dist[s][m] + dist[m][e];
                    }

                    if (dist2[s][e] > dist2[s][m] + dist2[m][e]) {
                        dist2[s][e] = dist2[s][m] + dist2[m][e];
                    }

                }
            }
        }

        double total = 0;
        double tomorrow = 0;

        for (int i = 1; i < M; i++) {
            int start = cities.get(travel[i - 1]);
            int end = cities.get(travel[i]);
            total += dist[start][end];
            tomorrow += dist2[start][end];

            // System.out.println(start + " " + end + " " + dist[start][end] + " " + dist2[start][end]);
        }
        tomorrow += R;

        if (tomorrow < total) System.out.println("Yes");
        else System.out.println("No");

    }
}
