#include<iostream>

using namespace std;

int plane[101][101];
int visited[101][101];

int dx[] = {1, -1, 0};
int dy[] = {0, 0, -1};
int ans;

bool check(int x, int y) {
	if (x < 0 || y < 0 || x >= 100 || y >= 100) return false;
    return true;
}

void dfs(int x, int y) {
    if (y == 0) {
        ans = x;
    	return;
    }
    for (int i = 0; i < 3; i++) {
    	int nx = x + dx[i];
        int ny = y + dy[i];
        if (check(nx, ny) && plane[ny][nx] != 0 && !visited[ny][nx]) {
        	visited[ny][nx] = 1;
            dfs(nx, ny);
            return;
        }
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int x, y;
        int t;
        cin >> t;
        for (int i = 0; i < 100; i++) {
        	for (int j = 0; j < 100; j++) {
            	cin >> plane[i][j];
                visited[i][j] = 0;
                if (plane[i][j] == 2) {
                	x = j;
                    y = i;
                }
            }
        }
        
        visited[y][x] = 1;
        dfs(x, y);
        cout << "#" << test_case << ' ' << ans << endl;
        
	}
	return 0;
}