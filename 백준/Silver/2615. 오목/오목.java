import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    
    public static int[][] board = new int[19][19];
    public static int[] dx = {1, 0, 1, -1}; // →, ↓, ↘, ↙
    public static int[] dy = {0, 1, 1, 1};

    public static boolean check(int x, int y, int color, int dir) {
        int cnt = 1;

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        // 앞쪽 방향으로 5개 확인
        while (nx >= 0 && nx < 19 && ny >= 0 && ny < 19 && board[nx][ny] == color) {
            cnt++;
            nx += dx[dir];
            ny += dy[dir];
        }

        // 반대 방향으로 확인 (6개 이상이면 오목 아님)
        nx = x - dx[dir];
        ny = y - dy[dir];
        while (nx >= 0 && nx < 19 && ny >= 0 && ny < 19 && board[nx][ny] == color) {
            cnt++;
            nx -= dx[dir];
            ny -= dy[dir];
        }

        return cnt == 5; // 정확히 5개만 인정
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        for (int i = 0; i < 19; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 19; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 19; j++) {
                if (board[i][j] == 1 || board[i][j] == 2) {
                    for (int dir = 0; dir < 4; dir++) {
                        if (check(i, j, board[i][j], dir)) {
                            // 반대 방향으로 한 칸 더 가서 더 작은 좌표가 있는지 확인
                            int px = i - dx[dir];
                            int py = j - dy[dir];

                            if (px >= 0 && px < 19 && py >= 0 && py < 19 && board[px][py] == board[i][j]) {
                                continue; // 더 앞에 같은 돌이 있으면 무효
                            }

                            System.out.println(board[i][j]);
                            System.out.println((i + 1) + " " + (j + 1));
                            return;
                        }
                    }
                }
            }
        }

        System.out.println(0);
    }
}
