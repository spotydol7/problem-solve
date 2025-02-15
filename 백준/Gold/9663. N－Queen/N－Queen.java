import java.util.Scanner;

public class Main {
    static int n;
    static int cnt;
    static boolean[] isThere1 = new boolean[40];
    static boolean[] isThere2 = new boolean[40];
    static boolean[] isThere3 = new boolean[40];
    public static void backtracting(int level) {
        if (level == n) {
            cnt++;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isThere1[i] || isThere2[i + level] || isThere3[level - i + n - 1]) continue;
            isThere1[i] = true;
            isThere2[i + level] = true;
            isThere3[level - i + n - 1] = true;

            backtracting(level + 1);

            isThere1[i] = false;
            isThere2[i + level] = false;
            isThere3[level - i + n - 1] = false;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = Integer.parseInt(sc.nextLine());
        backtracting(0);
        System.out.println(cnt);
    }
}
