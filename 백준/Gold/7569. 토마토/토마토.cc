#include<bits/stdc++.h>
using namespace std;

int board[101][101][101];
int depth[101][101][101];
int dh[6] = {0, 0, 0, 0, 1, -1};
int dr[6] = {1, -1, 0, 0, 0, 0};
int dc[6] = {0, 0, 1, -1, 0, 0};

int main() {
    int m, n, h;
    cin >> m >> n >> h;

    queue<tuple<int, int, int, int>> q;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> board[i][j][k];
                if (board[i][j][k] == 1) q.push({i, j, k, 0});
                if (board[i][j][k] == 0) depth[i][j][k] = -1;
            }
        }
    }

    while(!q.empty()) {
        int curH = get<0>(q.front());
        int curR = get<1>(q.front());
        int curC = get<2>(q.front());
        int curDepth = get<3>(q.front());
        q.pop();
        
        for (int i = 0; i < 6; i++) {
            int nh = curH + dh[i];
            int nr = curR + dr[i];
            int nc = curC + dc[i];

            if (nh < 0 || nh >= h || nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if (depth[nh][nr][nc] >= 0) continue;
            if (board[nh][nr][nc] == -1) continue;
            
            q.push({nh, nr, nc, curDepth + 1});
            depth[nh][nr][nc] = curDepth + 1;
        }
    }

    int max = -1;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (depth[i][j][k] == -1) {
                    cout << -1;
                    return 0;
                }
                max = depth[i][j][k] > max ? depth[i][j][k] : max;
            }
        }
    }

    cout << max;

    return 0;
}