import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Solution {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		for (int test_case = 1; test_case <= 10; test_case++) {
			int n = Integer.parseInt(br.readLine());
			
			char[] str = new char[n];
			String temp = br.readLine();
			for (int i = 0; i < n; i++) {
				str[i] = temp.charAt(i);
			}
			
			Stack<Character> stack = new Stack<>();
			
			boolean isPossible = true;
			
			for (int i = 0; i < n; i++) {
				if (str[i] == '(' || str[i] == '[' || str[i] =='{' || str[i] == '<') {
					stack.add(str[i]);
				}
				else if (str[i] == ')') {
					if (stack.peek() == '(') stack.pop();
					else isPossible = false;
				}
				else if (str[i] == ']') {
					if (stack.peek() == '[') stack.pop();
					else isPossible = false;
				}
				else if (str[i] == '}') {
					if (stack.peek() == '{') stack.pop();
					else isPossible = false;
				}
				else if (str[i] == '>') {
					if (stack.peek() == '<') stack.pop();
					else isPossible = false;
				}
			}
			
			if (isPossible) System.out.println("#" + test_case + " " + 1);
			else System.out.println("#" + test_case + " " + 0);	
		}
		
	}
}
