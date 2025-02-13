#include <bits/stdc++.h>
using namespace std;

int n, l, r;
int days;
int popularity[51][51];
int visited[51][51];
bool moved;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

bool isUnited(int x, int y, int nx, int ny) {
	if (abs(popularity[x][y] - popularity[nx][ny]) >= l && abs(popularity[x][y] - popularity[nx][ny]) <= r) return true;
	return false;
}

int main() {
	// 국경선을 공유하는 두 나라의 인구 차이가 L명 이상, R명 이하라면, 두 나라가 공유하는 국경선을 오늘 하루 동안 연다.
	cin >> n >> l >> r;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> popularity[i][j];
		}
	}

	while (1) {
		memset(visited, 0, sizeof(visited));
        bool isMoved = false;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]) {
					int sum = 0;
	                queue<pair<int, int>> q;
                    vector<pair<int, int>> group;
                    q.push({ i, j });
                    group.push_back({ i, j });
                    visited[i][j] = 1;
                    sum += popularity[i][j];

                    while (!q.empty()) {
                        int cur_x = q.front().first;
                        int cur_y = q.front().second;
                        q.pop();

                        for (int i = 0; i < 4; i++) {
                            int nx = cur_x + dx[i];
                            int ny = cur_y + dy[i];
                            if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;
                            if (visited[nx][ny]) continue;
                            if (isUnited(cur_x, cur_y, nx, ny)) {
                                q.push({ nx, ny });
                                group.push_back({ nx, ny });
                                visited[nx][ny] = 1;
                                sum += popularity[nx][ny];
                            }
                        }
                    }

                    if (group.size() > 1) {
                        isMoved = true;
                        sum = sum / group.size();
                        for (int i = 0; i < group.size(); i++) {
                            popularity[group[i].first][group[i].second] = sum;
                        }
                    }
				}
			}
		}

        if (!isMoved) break;
        days++;
	}

	cout << days;

	return 0;
}