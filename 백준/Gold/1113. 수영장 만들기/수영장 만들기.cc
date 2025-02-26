#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[51][51];
bool visited[51][51];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int h) {
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                if (board[i][j] <= h && !visited[i][j]) {
                    visited[i][j] = true;
                    q.push({i, j});
                }
            }
        }
    }
    
    while (!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = curX + dx[i];
            int ny = curY + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (visited[nx][ny]) continue;
            // 현재 높이 h보다 큰 칸은 물이 차오를 수 없으므로 지나가지 않음
            if (board[nx][ny] > h) continue;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++) {
            board[i][j] = str[j] - '0';
        }
    }

    int ans = 0;
    
    for (int h = 0; h <= 9; h++) {
        memset(visited, 0, sizeof(visited));
        
        bfs(h);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // 현재 높이와 같으면서 바깥이랑 연결안되면 물이 고임 ㅇㅇ
                if (board[i][j] == h) {
                    if (!visited[i][j]) ans++;
                    board[i][j]++; // 물 높이 증가
                }
            }
        }
    }
    
    cout << ans;
    return 0;
}
