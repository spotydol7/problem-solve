import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static int max = -1;
    static int[] dur;
    static int[] wt;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        dur = new int[N + 1];
        wt = new int[N + 1];

        for(int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());

            dur[i] = s;
            wt[i] = w;
        }

        backtracking(0, 0);

        System.out.println(max);
    }

    public static void backtracking(int depth, int cnt) {
        if (depth == N) {
            max = Math.max(max, cnt);
            return;
        }

        if (dur[depth] <= 0 || cnt == N - 1) {
            backtracking(depth + 1, cnt);
            return;
        }
        int temp = cnt;
        for (int i = 0; i < N; i++) {
            if (i == depth) continue;
            if (dur[i] <= 0) continue;

            crash(depth, i);
            if (dur[i] <= 0) cnt++;
            if (dur[depth] <= 0) cnt++;
            backtracking(depth + 1, cnt);

            reset(depth, i);
            cnt = temp;
        }
    }

    public static void crash(int hand, int idx) {
        dur[hand] -= wt[idx];
        dur[idx] -= wt[hand];
    }

    public static void reset(int hand, int idx) {
        dur[hand] += wt[idx];
        dur[idx] += wt[hand];
    }
}
