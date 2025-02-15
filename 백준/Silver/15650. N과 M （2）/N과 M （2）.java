import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int n;
    static int m;
    static int[] arr;
    public static void dfs(int level, int num) {
        if (level == m) {
            for (int val : arr) {
                System.out.print(val + " ");
            }
            System.out.println();
            return;
        }
        for (int i = num; i <= n; i++) {
                arr[level] = i;
                dfs(level + 1, i + 1);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        arr = new int[m];

        dfs(0, 1);
    }
}
