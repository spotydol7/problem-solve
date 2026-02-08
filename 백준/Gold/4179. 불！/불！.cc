#include <bits/stdc++.h>
using namespace std;

int R, C;
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };
int run[1001][1001];
int fire[1001][1001];
string board[1001];
queue<pair<int, int>> run_q;
queue<pair<int, int>> fire_q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(fire, -1, sizeof(fire));
    memset(run, -1, sizeof(run));

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        cin >> board[i];
        for (int j = 0; j < C; j++) {
            if (board[i][j] == 'J') {
                run_q.push({ i, j });
                run[i][j] = 0;
            }
            if (board[i][j] == 'F') {
                fire_q.push({ i, j });
                fire[i][j] = 0;
            }
        }
    }

    while (!fire_q.empty()) {
        auto cur = fire_q.front();
        fire_q.pop();
        int cur_r = cur.first;
        int cur_c = cur.second;

        for (int i = 0; i < 4; i++) {
            int nr = cur_r + dr[i];
            int nc = cur_c + dc[i];

            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if (board[nr][nc] == '#' || fire[nr][nc] >= 0) continue;
            fire[nr][nc] = fire[cur_r][cur_c] + 1;
            fire_q.push({ nr, nc });
        }
    }

    while (!run_q.empty()) {
        auto cur = run_q.front();
        run_q.pop();
        int cur_r = cur.first;
        int cur_c = cur.second;

        for (int i = 0; i < 4; i++) {
            int nr = cur_r + dr[i];
            int nc = cur_c + dc[i];

            if (nr < 0 || nr >= R || nc < 0 || nc >= C) {
                cout << run[cur_r][cur_c] + 1 << '\n';
                return 0;
            }

            if (run[nr][nc] >= 0 || board[nr][nc] == '#') continue;
            if (fire[nr][nc] != -1 && fire[nr][nc] <= run[cur_r][cur_c] + 1) continue;

            run[nr][nc] = run[cur_r][cur_c] + 1;
            run_q.push({ nr, nc });
        }
    }

    cout << "IMPOSSIBLE" << '\n';

    return 0;
}