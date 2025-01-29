#include <bits/stdc++.h>
using namespace std;

int board[201][201];
int visited[201][201][31];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int jumpx[8] = {1, 2, 1, 2, -1, -2, -1, -2};
int jumpy[8] = {2, 1, -2, -1, 2, 1, -2, -1};
int k, w, h;
queue<pair<pair<int, int>, pair<int, int>>> q;

int bfs(int x, int y) {
    q.push({{x, y}, {0, 0}});
    visited[x][y][0] = 1;

    while(!q.empty()) {
        auto cur = q.front();
        int jumped = cur.second.first;
        int cnt = cur.second.second;
        q.pop();

        if (cur.first.first == h - 1 && cur.first.second == w - 1) return cnt;
        if (jumped < k) {
            for (int i = 0; i < 8; i++) {
                int nx = cur.first.first + jumpx[i];
                int ny = cur.first.second + jumpy[i];
                if (nx >= h || nx < 0 || ny >= w || ny < 0) continue;
                if (visited[nx][ny][jumped + 1] != 0 || board[nx][ny] == 1) continue;
                visited[nx][ny][jumped + 1] = 1;
                q.push({{nx, ny}, {jumped + 1, cnt + 1}});
            }
        }
        for (int i = 0; i < 4; i++) {
            int nx = cur.first.first + dx[i];
            int ny = cur.first.second + dy[i];
            if (nx >= h || nx < 0 || ny >= w || ny < 0) continue;
            if (visited[nx][ny][jumped] != 0 || board[nx][ny] == 1) continue;
            visited[nx][ny][jumped] = 1;
            q.push({{nx, ny}, {jumped, cnt + 1}});
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> k;
    cin >> w >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> board[i][j];
        }
    }

    cout << bfs(0, 0);

    return 0;
}