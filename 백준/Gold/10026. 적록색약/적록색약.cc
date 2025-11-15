#include <bits/stdc++.h>
using namespace std;

const int R = 1;
const int G = 2;
const int B = 3;

int n;
int board[101][101];
int blind[101][101];
bool visited[101][101];
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
int sum = 0;

void dfs(int r, int c, int arr[][101]) {
    visited[r][c] = true;

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
        if (visited[nr][nc]) continue;
        if (arr[r][c] != arr[nr][nc]) continue;

        dfs(nr, nc, arr);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++) {
            if (str[j] == 'R') {
                board[i][j] = R;
                blind[i][j] = R;
            }
            if (str[j] == 'G') {
                board[i][j] = G;
                blind[i][j] = R;
            }
            if (str[j] == 'B') {
                board[i][j] = B;
                blind[i][j] = B;
            }
        }
    }

    int cnt = 0, blind_cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                dfs(i, j, board);
                cnt++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                dfs(i, j, blind);
                blind_cnt++;
            }
        }
    }

    cout << cnt << ' ' << blind_cnt << '\n';
    
    return 0;
}