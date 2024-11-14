#include <iostream>
#include <queue>
#include <climits>  // For INT_MAX
using namespace std;

int n;
int plane[101][101];
int work[101][101];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(int startx, int starty) {
    queue<pair<int, int>> q;
    q.push(make_pair(startx, starty));
    work[starty][startx] = plane[starty][startx];
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && ny >= 0 && nx < n && ny < n) { 
                int ncost = work[y][x] + plane[ny][nx];
                if (ncost < work[ny][nx]) {
                    work[ny][nx] = ncost;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main() {
    int T;

    cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case) {
        cin >> n;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%1d", &plane[i][j]);
                work[i][j] = INT_MAX;
            }
        }
		
        bfs(0, 0);
        cout << "#" << test_case << " " << work[n - 1][n - 1] << endl;
    }
    return 0;
}
