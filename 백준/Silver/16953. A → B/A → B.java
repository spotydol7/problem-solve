import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        long A = Long.parseLong(st.nextToken());
        long B = Long.parseLong(st.nextToken());

        Queue<long[]> q = new LinkedList<>();
        q.add(new long[]{A, 1});

        while (!q.isEmpty()) {
            long[] now = q.poll();
            long cur = now[0];
            long cnt = now[1];

            if (cur == B) {
                System.out.println(cnt);
                return;
            }

            if (cur * 2 <= B) {
                q.add(new long[]{cur * 2, cnt + 1});
            }

            if (cur * 10 + 1 <= B) {
                q.add(new long[]{cur * 10 + 1, cnt + 1});
            }
        }

        System.out.println(-1);
    }
}