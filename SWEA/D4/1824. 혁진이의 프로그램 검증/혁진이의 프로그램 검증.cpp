#include <iostream>
#include <random>
#include <cstring>

using namespace std;

int visit[22][22][4][16]; // x, y좌표, 방향, 메모리
char arr[22][22];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int row, column;

bool dfs(int x, int y, int dir, int mem) {
    bool result = false;
    
    if (visit[x][y][dir][mem]) return false;
    else visit[x][y][dir][mem] = 1;
    
    if (x >= column) x = 0;
    else if (x < 0) x = column - 1;
    if (y >= row) y = 0;
    else if (y < 0) y = row - 1;
	char cursor = arr[y][x];
    
    if (cursor - '0' <= 9 && cursor - '0' >= 0) mem = cursor - '0';
    else if (cursor == '>') dir = 0;
    else if (cursor == '<') dir = 1;
    else if (cursor == 'v') dir = 2;
    else if (cursor == '^') dir = 3;
    else if (cursor == '_') {
    	if (mem == 0) dir = 0;
        else dir = 1;
    }
    else if (cursor == '|') {
        if (mem == 0) dir = 2;
        else dir = 3;
    }
    else if (cursor == '+') mem = (mem + 1) % 16;
    else if (cursor == '-') {
        if (mem == 0) mem = 15;
        else mem = mem - 1;
    }
    else if (cursor == '@') return true;
    
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (nx < 0) nx = column - 1;
    else if (nx >= column) nx = 0;
    if (ny < 0) ny = row - 1;
    else if (ny >= row) ny = 0;
    
    if (cursor == '?') {
        for (int i = 0; i < 4; i++) {
        	int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0) nx = column - 1;
            else if (nx > column - 1) nx = 0;
            if (ny < 0) ny = row - 1;
            else if (ny > row - 1) ny = 0;
            result = max(result, dfs(nx, ny, i, mem));
        }
        return result;
    }
    else return max(result, dfs(nx, ny, dir, mem));
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int x, y;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int mem = 0;
		memset(arr, 0, sizeof(arr));
		cin >> row >> column;
        for (int i = 0; i < row; i++) {
        	for (int j  = 0; j < column; j++) {
            	cin >> arr[i][j];
            }
        }
        
        memset(visit, 0, sizeof(visit));
        string ans = dfs(0, 0, 0, 0) ? "YES" : "NO";
        cout << '#' << test_case << ' ' << ans << endl;
	}
	return 0;
}