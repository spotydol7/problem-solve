class Solution {
    int[] numbers;
    int target;
    
    public int solution(int[] numbers, int target) {
        this.numbers = numbers;
        this.target = target;
        
        int answer = dfs(0, 0);
        
        return answer;
    }
    
    public int dfs(int depth, int sum) {
        if (depth == numbers.length) {
            if (sum == target) return 1;
            else return 0;
        }
        
         return dfs(depth + 1, sum + numbers[depth]) + dfs(depth + 1, sum - numbers[depth]);
    }
}