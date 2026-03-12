#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 0;
int _k;
vector<vector<int>> _dungeons;
bool visited[9];
int sequence[9];

void dfs(int depth) {
    if (depth == _dungeons.size()) {
        int temp = _k;
        int sum = 0;
        for (int i = 0; i < depth; i++) {
            int seq = sequence[i];
            if (temp >= _dungeons[seq][0]) {
                temp -= _dungeons[seq][1];
                sum++;
            }
            else continue;
        }
        answer = max(sum, answer);
    }
    
    for (int i = 0; i < _dungeons.size(); i++) {
        if (visited[i]) continue;
        visited[i] = true;
        sequence[depth] = i;
        dfs(depth + 1);
        visited[i] = false;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    _k = k;
    _dungeons = dungeons;
    
    dfs(0);
    
    return answer;
}