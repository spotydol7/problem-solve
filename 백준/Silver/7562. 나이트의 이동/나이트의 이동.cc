#include <bits/stdc++.h>
using namespace std;

int board[301][301];
int visited[301][301];
int dx[8] = {2, 1, 2, 1, -2, -1, -2, -1};
int dy[8] = {1, 2, -1, -2, 1, 2, -1, -2};

int main() {
    int T;
    cin >> T;
    while (T--) {
        memset(board, 0, sizeof(board));
        memset(visited, 0, sizeof(visited));
        int n;
        cin >> n;
        int a, b, c, d;
        cin >> a >> b;
        cin >> c >> d;
        if (a == c && b == d) {
            cout << 0 << '\n';
            continue;
        }
        queue<pair<int, int>> q;
        q.push({a, b});
        visited[a][b] = 1;
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;
                if (visited[nx][ny] > 0) continue;
                q.push({nx, ny});
                visited[nx][ny] = visited[x][y] + 1;
            }
        }
        cout << visited[c][d] - 1 << '\n';
    }
    return 0;
}