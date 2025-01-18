#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
int arr[101];
int visited[101];

void bfs() {
    queue<int> q;
    visited[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 1; i <= 6; i++) {
            int next = cur + i;
            if (next > 100) continue;
            if (arr[next] != 0) next = arr[next];
            if (visited[next] == -1) {
                visited[next] = visited[cur] + 1;
                q.push(next);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, x, y;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        arr[x] = y;
    }
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        arr[x] = y;
    }
    memset(visited, -1, sizeof(visited));

    bfs();
    cout << visited[100] << '\n';

    return 0;
}