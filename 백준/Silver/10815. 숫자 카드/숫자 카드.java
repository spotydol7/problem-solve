import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int[] arr;

    public static int binarySearch(int[] arr, int n, int target) {
        int first = 0;
        int last = n - 1;
        int mid = 0;

        while (first <= last) {
            mid = (first + last) / 2;
            if (arr[mid] == target) {
                return 1;
            }

            if (arr[mid] < target) {
                first = mid + 1;
            } else  {
                last = mid - 1;
            }
        }
        return 0;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(bf.readLine());
        arr = new int[n];

        StringTokenizer st = new StringTokenizer(bf.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr);

        StringBuilder sb = new StringBuilder();
        int m = Integer.parseInt(bf.readLine());
        st = new StringTokenizer(bf.readLine());
        for (int i = 0; i < m; i++) {
            int temp = Integer.parseInt(st.nextToken());
            sb.append(binarySearch(arr, n, temp) + " ");
        }

        bw.write(sb.toString() + "\n");
        bw.flush();
        bw.close();
        bf.close();
    }
}
