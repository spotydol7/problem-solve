
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        int[] temp = new int[N + 1];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            temp[i] = Integer.parseInt(st.nextToken());
        }

        int sum = 0;
        for (int i = 0; i < K; i++) {
            sum += temp[i];
        }
        int max = sum;

        for (int i = K; i < N; i++) {
            sum += temp[i];
            sum -= temp[i - K];
            max = Math.max(sum, max);
        }

        System.out.println(max);
    }
}
