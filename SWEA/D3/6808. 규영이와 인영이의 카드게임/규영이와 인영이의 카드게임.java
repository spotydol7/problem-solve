import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {

	static int[] order = new int[9];
	static int[] fixedOrder = new int[9];
	static int[] nums = new int[19];
	static int ans = 0;
	static int sum1 = 0, sum2 = 0;
	
	public static void dfs(int level) {
		if (level == 9) {
			sum1 = 0;
			sum2 = 0;
			for (int i = 0; i < 9; i++) {
				if (order[i] > fixedOrder[i]) {
					sum1 += order[i] + fixedOrder[i];
				}
				else sum2 += order[i] + fixedOrder[i];
			}
			if (sum1 > sum2) ans++; 
			return;
		}
		for (int i = 1; i <= 18; i++) {
			if (nums[i] != 1) {
				order[level] = i;
				nums[i] = 1;
				dfs(level + 1);
				nums[i] = 0;
			}
		}
	}
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		
		for (int test_case = 1; test_case <= T; test_case++) {
			ans = 0;
			order = new int[9];
			nums = new int[19];
			fixedOrder = new int[9];
			
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int i = 0; i < 9; i++) {
				int temp = Integer.parseInt(st.nextToken());
				nums[temp] = 1; // 숫자 사용되었는지
				fixedOrder[i] = temp; // 고정된 순서
			}
			
			dfs(0);
			
			int ans2 = 362880 - ans;
			
			System.out.println("#" + test_case + " " + ans2 + " " + ans);
		}
		
	}
}
