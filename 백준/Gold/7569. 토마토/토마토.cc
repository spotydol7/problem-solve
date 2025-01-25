#include <bits/stdc++.h>
using namespace std;

int m, n, h, cnt = 0;
int tomato[101][101][101];
int d[101][101][101];
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
queue<pair<pair<int, int>, int>> Q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> h;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> tomato[i][j][k];
                if (tomato[i][j][k] == 1) 
                    Q.push({{i, j}, k});
                if (tomato[i][j][k] == 0) 
                    d[i][j][k] = -1;
            }
        }
    }

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int i = 0; i < 6; i++) {
            int nx = cur.first.first + dx[i];
            int ny = cur.first.second + dy[i];
            int nz = cur.second + dz[i];

            if (nx < 0 || nx >= h || ny < 0 || ny >= n || nz < 0 || nz >= m) continue;
            if (d[nx][ny][nz] >= 0) continue;
            d[nx][ny][nz] = d[cur.first.first][cur.first.second][cur.second] + 1;
            Q.push({{nx, ny}, nz});
        }
    }

    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (d[i][j][k] == -1) {
                    cout << -1;
                    return 0;
                }
                ans = max(ans, d[i][j][k]);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}