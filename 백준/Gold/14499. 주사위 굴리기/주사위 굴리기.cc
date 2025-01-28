#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, k;
int board[21][21];
int dice[6];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

/*
  2
4 1 3
  5
  6
*/

void roll(int d) {
    int temp[6];
    for (int i = 0; i < 6; i++) {
        temp[i] = dice[i];
    }
    if (d == 0) {
        dice[0] = temp[3];
        dice[2] = temp[0];
        dice[3] = temp[5];
        dice[5] = temp[2];
    }
    else if (d == 1) {
        dice[0] = temp[2];
        dice[2] = temp[5];
        dice[3] = temp[0];
        dice[5] = temp[3];
    }
    else if (d == 2) {
        dice[0] = temp[4];
        dice[1] = temp[0];
        dice[4] = temp[5];
        dice[5] = temp[1];
    }
    else {
        dice[0] = temp[1];
        dice[1] = temp[5];
        dice[4] = temp[0];
        dice[5] = temp[4];
    }
    if (board[x][y] == 0) {
        board[x][y] = dice[5];
    }
    else {
        dice[5] = board[x][y];
        board[x][y] = 0;
    }
    cout << dice[0] << '\n';
}

int main() {
    int command;
    cin >> n >> m >> x >> y >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < k; i++) {
        cin >> command; // 1 2 3 4 동 서 북 남
        command--;
        int nx = x + dx[command];
        int ny = y + dy[command];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        else {
            x = nx;
            y = ny;
            roll(command);
        }
    }
    return 0;
}