#include <bits/stdc++.h>
using namespace std;

int n;
int cnt = 0;
int dx[3] = { 1, 1, 0 };
int dy[3] = { 0, 1, 1 }; // → ↘ ↓
int arr[17][17];
int visited[17][17];

queue< pair< pair<int,int>, pair<int,int> > > q;

void bfs(int x, int y) {
    q.push({ { x, y }, { x - 1, y } });
    visited[y][x] = 1;
    
    while (!q.empty()) {
        int cur_x = q.front().first.first;
        int cur_y = q.front().first.second;
        int tail_x = q.front().second.first;
        int tail_y = q.front().second.second;
        q.pop();
        
        if (cur_x == n - 1 && cur_y == n - 1) {
            cnt++;
            continue;
        }
        
        // 꼬리와 머리 좌표로 파이프의 방향 구분
        int dir;
        if(cur_y == tail_y)
            dir = 0; // 가로
        else if(cur_x == tail_x)
            dir = 2; // 세로
        else
            dir = 1; // 대각
        
        // 오른쪽 - 가로, 대각인 경우 가능
        if (dir == 0 || dir == 1) {
            int nx = cur_x + dx[0];
            int ny = cur_y + dy[0];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) { }
            else if (arr[ny][nx] == 0) {
                // 머리 꼬리 이동
                q.push({ { nx, ny }, { cur_x, cur_y } });
            }
        }
        
        // 오른쪽 아래 - 모든 방향에서 가능
        {
            int nx = cur_x + dx[1];
            int ny = cur_y + dy[1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) { }
            else if (arr[cur_y][cur_x+1] == 0 && arr[cur_y+1][cur_x] == 0 && arr[ny][nx] == 0) {
                q.push({ { nx, ny }, { cur_x, cur_y } });
            }
        }
        
        // 아래 - 세로, 대각인 경우 가능
        if (dir == 2 || dir == 1) {
            int nx = cur_x + dx[2];
            int ny = cur_y + dy[2];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) { }
            else if (arr[ny][nx] == 0) {
                q.push({ { nx, ny }, { cur_x, cur_y } });
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    
    bfs(1, 0);
    cout << cnt;
    
    return 0;
}
