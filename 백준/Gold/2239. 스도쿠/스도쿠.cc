#include <bits/stdc++.h>
using namespace std;

int board[10][10];
vector<pair<int, int>> empty_v;

bool check(int r, int c, int num) {
    for (int i = 1; i <= 9; i++) {
        if (board[r][i] == num && i != c) return false;
        if (board[i][c] == num && i != r) return false;

        int nr = (r - 1) / 3 * 3 + 1 + (i - 1) / 3;
        int nc = (c - 1) / 3 * 3 + 1 + (i - 1) % 3;
        if(board[nr][nc] == num && !(nr == r && nc == c)) return false;
    }
    
    return true;
}

void backtracking(int depth) {
    if (depth == empty_v.size()) {
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                cout << board[i][j];
            }
            cout << '\n';
        }
        exit(0);
    }

    int r = empty_v[depth].first;
    int c = empty_v[depth].second;

    for (int num = 1; num <= 9; num++) {
        if (check(r, c, num)) {
            board[r][c] = num;
            backtracking(depth + 1);
            board[r][c] = 0;
        }
    }
    return;
}

int main() {
    for (int i = 1; i <= 9; i++) {
        string str;
        cin >> str;
        for (int j = 1; j <= 9; j++) {
            board[i][j] = str[j - 1] - '0';
            if (board[i][j] == 0) empty_v.push_back({i, j});
        }
    }

    backtracking(0);

    return 0;
}