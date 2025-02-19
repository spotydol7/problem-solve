import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	static int[][] board;
	static boolean[][] visited;
	
	static int[] dx = {1, -1, 0};
	static int[] dy = {0, 0, -1};
	static int ans;
	
	public static boolean check(int x, int y) {
		if (x < 0 || y < 0 || x >= 100 || y >= 100) return false;
	    return true;
	}
	
	public static void dfs(int x, int y) {
		if (y == 0) {
	        ans = x;
	    	return;
	    }
	    for (int i = 0; i < 3; i++) {
	    	int nx = x + dx[i];
	        int ny = y + dy[i];
	        if (check(nx, ny) && board[ny][nx] != 0 && !visited[ny][nx]) {
	        	visited[ny][nx] = true;
	            dfs(nx, ny);
	            return;
	        }
	    }
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for (int test_case = 1; test_case <= 10; test_case++) {
			int x = 0, y = 0;
			int t = Integer.parseInt(br.readLine());
			
			board = new int[100][100];
			visited = new boolean[100][100];
			
			for (int i = 0; i < 100; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				for (int j = 0; j < 100; j++) {
					board[i][j] = Integer.parseInt(st.nextToken());
					visited[i][j] = false;
					if (board[i][j] == 2) {
						x = j;
						y = i;
					}
				}
			}
			
			visited[y][x] = true;
	        dfs(x, y);
	        
	        System.out.println("#" + test_case + " " + ans);
		}
	}
}