#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int graph[1001][1001];
int result[1001][1001];
bool visited[1001][1001];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int n, m;

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({ x, y });
    visited[x][y] = true;
    result[x][y] = 0;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        for (int v = 0; v < 4; v++) {
            int nx = cur.first + dx[v];
            int ny = cur.second + dy[v];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            if (graph[nx][ny] == 1 && !visited[nx][ny]) {
                q.push({ nx, ny });
                visited[nx][ny] = true;
                result[nx][ny] = result[cur.first][cur.second] + 1;
            }
        }
        q.pop();
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int x, y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int temp;
            cin >> temp;
            graph[i][j] = temp;

            if (temp == 2) {
                x = i;
                y = j;
            }
        }
    }

    bfs(x, y);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (result[i][j] == 0 && graph[i][j] == 1)
                cout << -1 << ' ';
            else
                cout << result[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}