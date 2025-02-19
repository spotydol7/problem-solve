import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution {
	static int[][] board;
	static boolean[][] visited;
	static int cnt = 1;
	static int dir = 0;
	static int[] dx = {1, 0, -1, 0};
	static int[] dy = {0, 1, 0, -1};
	
	public static void dfs(int x, int y, int n) {
		visited[y][x] = true;
	    board[y][x] = cnt;
	    cnt++;
	    int nx = x + dx[dir];
	    int ny = y + dy[dir];
	    if (nx == -1 || nx >= n || ny >= n || visited[ny][nx]) {
	        dir = (dir + 1) % 4;
	        nx = x + dx[dir];
	        ny = y + dy[dir];
	    }
	    if (ny >= 0 && nx >= 0 && nx < n && ny < n && !visited[ny][nx]) {
	    	dfs(nx, ny, n);
	    }
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			int n = Integer.parseInt(br.readLine());
			board = new int[n][n];
			visited = new boolean[n][n];
			cnt = 1;
			dir = 0;
			dfs(0, 0, n);
			
			System.out.println("#" + t);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					System.out.print(board[i][j] + " ");
				}
				System.out.println();
			}
			
			for (int i = 0; i < n; i++) {
	        	for (int j = 0; j < n; j++) {
	            	visited[i][j] = false;
	                board[i][j] = 0;
	            }
	        }
			
		}
	}
}

