#include <bits/stdc++.h>
using namespace std;

vector<int> adjacent[501];
bool visited[501];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adjacent[a].push_back(b);
        adjacent[b].push_back(a);
    }
    
    queue<pair<int, int>> q; // 친구번호, depth pair
    q.push({1, 0});
    visited[1] = true;
    
    int count = 0;
    while (!q.empty()) {
        int cur = q.front().first;
        int depth = q.front().second;
        q.pop();
        
        if (depth >= 2) continue;
        
        for (int next : adjacent[cur]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push({next, depth + 1});
                count++;
            }
        }
    }
    
    cout << count;
    return 0;
}
