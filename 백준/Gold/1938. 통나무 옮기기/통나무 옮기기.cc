#include <bits/stdc++.h>
using namespace std;

int n;
char board[51][51];

bool visited[51][51][2] = {false};

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

struct State {
    int r, c, orientation, moves;
};

/*
struct Log {
    pair<int, int> a;
    pair<int, int> b;
    pair<int, int> c;
};

queue<Log> q;
*/

bool canMove(State cur, int dir) {
    if(cur.orientation == 0) {
        if(dir == 0) {
            int nr = cur.r - 1;
            if(nr < 0) return false;
            for (int j = cur.c - 1; j <= cur.c + 1; j++){
                if(j < 0 || j >= n) return false;
                if(board[nr][j] == '1') return false;
            }
            return true;
        }
        else if(dir == 1) {
            int nr = cur.r + 1;
            if(nr >= n) return false;
            for (int j = cur.c - 1; j <= cur.c + 1; j++){
                if(j < 0 || j >= n) return false;
                if(board[nr][j] == '1') return false;
            }
            return true;
        }
        else if(dir == 2) {
            if(cur.c - 2 < 0) return false;
            int r = cur.r;
            for (int j = cur.c - 2; j <= cur.c; j++){
                if(j < 0 || j >= n) return false;
                if(board[r][j] == '1') return false;
            }
            return true;
        }
        else if(dir == 3) {
            if(cur.c + 2 >= n) return false;
            int r = cur.r;
            for (int j = cur.c; j <= cur.c + 2; j++){
                if(j < 0 || j >= n) return false;
                if(board[r][j] == '1') return false;
            }
            return true;
        }
    }
    else {
        if(dir == 0) {
            if(cur.r - 2 < 0) return false;
            int c = cur.c;
            for (int i = cur.r - 2; i <= cur.r; i++){
                if(i < 0 || i >= n) return false;
                if(board[i][c] == '1') return false;
            }
            return true;
        }
        else if(dir == 1) {
            if(cur.r + 2 >= n) return false;
            int c = cur.c;
            for (int i = cur.r; i <= cur.r + 2; i++){
                if(i < 0 || i >= n) return false;
                if(board[i][c] == '1') return false;
            }
            return true;
        }
        else if(dir == 2) {
            if(cur.c - 1 < 0) return false;
            for (int i = cur.r - 1; i <= cur.r + 1; i++){
                if(i < 0 || i >= n) return false;
                if(board[i][cur.c - 1] == '1') return false;
            }
            return true;
        }
        else if(dir == 3) {
            if(cur.c + 1 >= n) return false;
            for (int i = cur.r - 1; i <= cur.r + 1; i++){
                if(i < 0 || i >= n) return false;
                if(board[i][cur.c + 1] == '1') return false;
            }
            return true;
        }
    }
    return false;
}

bool canRotate(State cur) {
    for (int i = cur.r - 1; i <= cur.r + 1; i++){
        for (int j = cur.c - 1; j <= cur.c + 1; j++){
            if(i < 0 || i >= n || j < 0 || j >= n) return false;
            if(board[i][j] == '1') return false;
        }
    }
    return true;
}

int bfs(State startState, State endState) {
    queue<State> q;
    q.push(startState);
    visited[startState.r][startState.c][startState.orientation] = true;
    
    while(!q.empty()){
        State cur = q.front();
        q.pop();
        
        if(cur.r == endState.r && cur.c == endState.c && cur.orientation == endState.orientation)
            return cur.moves;
        
        for (int i = 0; i < 4; i++){
            State next = cur;
            next.r = cur.r + dr[i];
            next.c = cur.c + dc[i];
            next.moves = cur.moves + 1;
            next.orientation = cur.orientation;
            if(next.r < 0 || next.r >= n || next.c < 0 || next.c >= n)
                continue;
            if(!canMove(cur, i))
                continue;
            if(!visited[next.r][next.c][next.orientation]){
                visited[next.r][next.c][next.orientation] = true;
                q.push(next);
            }
        }
        
        if(canRotate(cur)){
            State next = cur;
            next.moves = cur.moves + 1;
            next.orientation = (cur.orientation == 0 ? 1 : 0);
            if(!visited[next.r][next.c][next.orientation]){
                visited[next.r][next.c][next.orientation] = true;
                q.push(next);
            }
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;

    pair<int, int> startPos = {-1,-1}, midPos = {-1,-1}, endPos = {-1,-1};
    pair<int, int> endS = {-1,-1}, endM = {-1,-1}, endE = {-1,-1};
    
    int bCount = 0, eCount = 0;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        for(int j = 0; j < n; j++){
            board[i][j] = str[j];
            if(board[i][j] == 'B'){
                if(bCount == 0) startPos = {i, j};
                else if(bCount == 1) midPos = {i, j};
                else if(bCount == 2) endPos = {i, j};
                bCount++;
            }
            if(board[i][j] == 'E'){
                if(eCount == 0) endS = {i, j};
                else if(eCount == 1) endM = {i, j};
                else if(eCount == 2) endE = {i, j};
                eCount++;
            }
        }
    }
    
    int startOrientation = (startPos.first == midPos.first ? 0 : 1);
    int endOrientation = (endS.first == endM.first ? 0 : 1);
    
    State startState = {midPos.first, midPos.second, startOrientation, 0};
    State endState = {endM.first, endM.second, endOrientation, 0};
    
    cout << bfs(startState, endState) << "\n";
    
    return 0;
}
