import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	static int[] arr;
	static int minimum;
	
	static void DP(int n) {
		arr[1] = 1;
		
		for (int i = 2; i <= n; i++) {
			minimum = Integer.MAX_VALUE;
			for (int j = 1; j * j <= i; j++) {
				minimum = Math.min(minimum, arr[i - j * j]);
			}
			arr[i] = minimum + 1;
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(bf.readLine());
		arr = new int[n + 1];
		DP(n);
		
		System.out.println(arr[n]);
	}
}
