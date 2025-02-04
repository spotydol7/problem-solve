import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Set<String> s = new HashSet<String>();

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        for (int i = 0; i < n; i++) {
            s.add(br.readLine());
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            String temp = br.readLine();
            if (s.contains(temp)) ans++;
        }

        br.close();
        System.out.println(ans);
    }
}
