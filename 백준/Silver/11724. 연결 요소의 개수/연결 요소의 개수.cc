#include <bits/stdc++.h>
using namespace std;

int n, m, u, v;
int adjacent[1002][1002];
int visited[1002];

void dfs(int cur) {
    visited[cur] = 1;

    for (int i = 1; i <= n; i++) {
        if (adjacent[cur][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adjacent[u][v] = 1;
        adjacent[v][u] = 1;
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cnt++;
            dfs(i);
        }
    }

    cout << cnt << '\n';

    return 0;
}