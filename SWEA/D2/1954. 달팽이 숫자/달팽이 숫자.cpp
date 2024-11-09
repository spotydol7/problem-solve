#include<iostream>

using namespace std;

int plane[11][11];
int visited[11][11];
int cnt = 1;
int dir = 0;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int x, int y, int n) {
	visited[y][x] = 1;
    plane[y][x] = cnt++;
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (nx == -1 || nx >= n || ny >= n || visited[ny][nx] == 1) {
        dir = (dir + 1) % 4;
        nx = x + dx[dir];
        ny = y + dy[dir];
    }
    if (ny >= 0 && nx >= 0 && nx < n && ny < n && visited[ny][nx] == 0) {
    	dfs(nx, ny, n);
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
    int n;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;
        cnt = 1;
        dir = 0;
        dfs(0, 0, n);
        cout << "#" << test_case << endl;
        for (int i = 0; i < n; i++) {
        	for (int j = 0; j < n; j++) {
            	cout << plane[i][j] << ' ';
            }
            cout << endl;
        }
        for (int i = 0; i < 11; i++) {
        	for (int j = 0; j < 11; j++) {
            	visited[i][j] = 0;
                plane[i][j] = 0;
            }
        }
	}
	return 0;
}