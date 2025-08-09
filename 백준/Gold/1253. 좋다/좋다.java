import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int N = Integer.parseInt(st.nextToken());
        int ans = 0;
        int[] arr = new int[N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr);

        for (int i = 0; i < N; i++) {
            int beg = 0;
            int end = N - 1;
            while(beg < end) {
                if (beg == i) {
                    beg++;
                    continue;
                }
                if (end == i) {
                    end--;
                    continue;
                }

                if (arr[beg] + arr[end] == arr[i]) {
                    ans++;
                    break;
                } else if (arr[beg] + arr[end] < arr[i]) {
                    beg++;
                } else if (arr[beg] + arr[end] > arr[i]) {
                    end--;
                }
            }
        }

        System.out.println(ans);
    }
}