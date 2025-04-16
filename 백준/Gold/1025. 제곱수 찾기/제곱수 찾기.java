import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int[][] board;
    static boolean[][] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        board = new int[N + 1][M + 1];

        for (int i = 0; i < N; i++) {
            String str = br.readLine();
            for (int j = 0; j < M; j++) {
                board[i][j] = str.charAt(j) - '0';
            }
        }

        int max = -1;

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                for (int dr = -N; dr < N; dr++) {
                    for (int dc = -M; dc < M; dc++) {
                        if (dr == 0 && dc == 0) continue;
                        int nr = r;
                        int nc = c;
                        int num = 0;
                        while (nr >= 0 && nr < N && nc >= 0 && nc < M) {
                            num *= 10;
                            num += board[nr][nc];
                            if (isPow(num)) max = Math.max(num, max);
                            nr += dr;
                            nc += dc;
                        }
                    }
                }
            }
        }

        System.out.println(max);
    }

    public static boolean isPow(int n) {
        int rt = (int)Math.sqrt(n);
        if (n == rt * rt) return true;
        return false;
    }
}
