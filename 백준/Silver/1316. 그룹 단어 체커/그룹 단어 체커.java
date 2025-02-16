import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            boolean[] alpha = new boolean[26];
            boolean flag = true;
            int idx = str.charAt(0) - 'a';
            alpha[idx] = true;
            for(int j = 1; j < str.length(); j++) {
                if (str.charAt(j) == str.charAt(j - 1)) continue;
                idx = str.charAt(j) - 'a';
                if (alpha[idx]) flag = false;
                alpha[idx] = true;
            }
            if (flag) ans++;
        }

        System.out.println(ans);
    }
}
