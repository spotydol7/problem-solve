#include <string>
#include <vector>

using namespace std;

bool visited[201];

void dfs(int from, int n, vector<vector<int>> &computers) {
    for (int i = 0; i < n; i++) {
        if (from != i && computers[from][i] == 1 && visited[i] == 0) {
            visited[i] = true;
            dfs(i, n, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        
        cnt++;
        visited[i] = true;
        
        dfs(i, n, computers);
    }
    return cnt;
}