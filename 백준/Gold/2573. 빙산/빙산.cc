#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[301][301];
int visited[301][301];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void melt() {
    int temp[301][301] = {0};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] > 0) {
                int water = 0;
                for (int d = 0; d < 4; d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if (nx >= 0 && nx < N && ny >= 0 && ny < M && arr[nx][ny] == 0) {
                        water++;
                    }
                }
                temp[i][j] = max(0, arr[i][j] - water);
            }
        }
    }

    memcpy(arr, temp, sizeof(arr));
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 1;

    while (!q.empty()) {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = curx + dx[d];
            int ny = cury + dy[d];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (!visited[nx][ny] && arr[nx][ny] > 0) {
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int cnt() {
    memset(visited, 0, sizeof(visited));
    int count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j] && arr[i][j] > 0) {
                bfs(i, j);
                count++;
            }
        }
    }

    return count;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    int year = 0;

    while (1) {
        int num = cnt();
        if (num == 0) {
            cout << 0 << '\n';
            break;
        }
        if (num >= 2) {
            cout << year << '\n';
            break;
        }
        melt();
        year++;
    }

    return 0;
}
