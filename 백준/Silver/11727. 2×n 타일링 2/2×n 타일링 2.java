import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static int[] arr;
    static void DP(int n) {
        arr[1] = 1;
        arr[2] = 3;
        arr[3] = 5;
        for (int i = 4; i <= n; i++) {
            arr[i] = (arr[i - 1] % 10007 + 2 * arr[i - 2] % 10007) % 10007;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bf.readLine());
        arr = new int[n + 4];
        DP(n);

        System.out.println(arr[n]);
    }
}
