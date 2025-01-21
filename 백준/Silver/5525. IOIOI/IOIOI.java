import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static int n;
    static int m;
    static int cnt;
    static int ans;
    static char[] str;

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(bf.readLine());
        m = Integer.parseInt(bf.readLine());
        str = new char[m + 1];

        String line = bf.readLine();
        for (int i = 0; i < m; i++) {
            str[i] = line.charAt(i);
        }

        cnt = 0;
        ans = 0;
        for (int i = 1; i < m - 1; i++) {
            if (str[i - 1] == 'I' && str[i] == 'O' && str[i + 1] == 'I') {
                cnt++;

                if (cnt == n) {
                    cnt--;
                    ans++;
                }
                i++;
            }
            else cnt = 0;
        }

        System.out.println(ans);
    }
}
