#include <bits/stdc++.h>
using namespace std;

int n,m;
int r,c,d;
int board_[52][52];  // 0:빈칸,1:벽
int visited[52][52]; // 청소 여부(0:미청소,1:청소됨)
int cnt=0;           // 청소한 칸 수

// 북(0), 동(1), 남(2), 서(3)
int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};

// 왼쪽으로 90도 회전
void turnLeft(){
    d = (d + 3) % 4;
}

// 뒤쪽 방향 구하기
int backDir(int d){
    return (d + 2) % 4;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    cin >> r >> c >> d; 
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board_[i][j];
        }
    }

    while(true){
        // 현재칸 청소
        if(!visited[r][c]){
            visited[r][c] = 1;
            cnt++;
        }

        // 왼쪽칸 탐색
        bool moved = false;
        for(int i=0; i<4; i++){
            turnLeft(); // 왼쪽 회전
            int nr = r + dr[d];
            int nc = c + dc[d];

            // 빈 칸 + 미청소면 전진
            if(board_[nr][nc] == 0 && !visited[nr][nc]){
                r = nr;
                c = nc;
                moved = true;
                break;
            }
        }

        // 네 방향 모두 청소돼있거나 벽
        if(!moved){
            // 뒤로 갈 수 있으면 후진
            int bd = backDir(d);
            int nr = r + dr[bd];
            int nc = c + dc[bd];
            // 벽이면 멈춤
            if(board_[nr][nc] == 1){
                break;
            }
            // 뒤가 벽 아니면 후진
            r = nr;
            c = nc;
        }
    }

    cout << cnt << '\n';
    return 0;
}