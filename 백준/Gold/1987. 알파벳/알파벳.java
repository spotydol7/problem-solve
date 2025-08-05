
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

    static int R, C, ans = -1;
    static char[][] board;
    static int[] dr = {1, -1, 0, 0};
    static int[] dc = {0, 0, 1, -1};
    static Set<Character> alphabet = new HashSet<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        board = new char[R][C];

        for (int i = 0; i < R; i++) {
            String str = br.readLine();
            for (int j = 0; j < C; j++) {
                board[i][j] = str.charAt(j);
            }
        }

        alphabet.add(board[0][0]);

        dfs(0, 0, 1);
        System.out.println(ans);
    }

    public static void dfs(int r, int c, int depth) {
        ans = Math.max(ans, depth);

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if (alphabet.contains(board[nr][nc])) continue;

            alphabet.add(board[nr][nc]);
            dfs(nr, nc, depth + 1);
            alphabet.remove(board[nr][nc]);
        }
    }
}
