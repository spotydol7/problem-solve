import java.io.*;
import java.util.*;

public class Main {

    static class Item {
        int w;
        int v;

        Item(int w, int v) {
            this.w = w;
            this.v = v;
        }
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        int[][] dp = new int[N + 1][K + 1];
        ArrayList<Item> items = new ArrayList<>();
        items.add(new Item(-1, -1));

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int w = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            
            items.add(new Item(w, v));
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= K; j++) {
                int curW = items.get(i).w;
                int curV = items.get(i).v;

                if (curW > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - curW] + curV);
                }
            }
        }

        System.out.println(dp[N][K]);
    }
}