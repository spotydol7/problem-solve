import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int isCycle(int[] arr, int[] num, int start) {
    if (num[start - 1] == 0) {
        return 0;
    }

    int current = start;
    while (num[current - 1] != 0) {
        int next = arr[current - 1];
        num[current - 1] = 0;
        current = next;
    }

    return 1;
}

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int T = Integer.parseInt(br.readLine());

        for (int test_case = 0; test_case < T; test_case++) {
            int N = Integer.parseInt(br.readLine());
            int[] arr = new int[N];
            int[] num = new int[N];

            StringTokenizer st = new StringTokenizer(br.readLine());

            for (int i = 0; i < N; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
                num[i] = i + 1;
            }

            int ans = 0;
            for (int i = 0; i < N; i++) {
                if (num[i] != 0)
                    ans += isCycle(arr, num, num[i]);
            }
            System.out.println(ans);
        }
    }
}
