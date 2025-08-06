class Solution {
    public static boolean[] visited;
    
    public int solution(int n, int[][] computers) {
        int answer = 0;
        visited = new boolean[n];
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, n, computers);
                answer++;
            }
        }
        
        return answer;
    }
    
    public void dfs(int computer, int n, int[][] computers) {
        visited[computer] = true;
        
        for (int i = 0; i < n; i++) {
            if (computers[computer][i] == 1 && !visited[i]) {
                dfs(i, n, computers);
            }
        }
    }
}