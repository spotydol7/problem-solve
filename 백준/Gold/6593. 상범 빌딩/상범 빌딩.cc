#include <bits/stdc++.h>
using namespace std;

int l = -1, r = -1, c = -1;
char building[31][31][31];
int visited[31][31][31];
int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

void bfs(int x, int y, int z) {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {x, y}, z });
	visited[x][y][z] = 1;
	while (!q.empty()) {
		auto cur = q.front();
		int cur_x = cur.first.first;
		int cur_y = cur.first.second;
		int cur_z = cur.second;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];
			int nz = cur_z + dz[i];
			if (nx >= l || nx < 0 || ny >= r || ny < 0 || nz >= c || nz < 0) continue;
			if (visited[nx][ny][nz] != 0 || building[nx][ny][nz] == '#') continue;
			q.push({ {nx, ny}, nz });
			visited[nx][ny][nz] = visited[cur_x][cur_y][cur_z] + 1;
		}
	}
}

int main() {
	int x, y, z, fx, fy, fz;
	while (true) {
		memset(visited, 0, sizeof(visited));
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0) break;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					cin >> building[i][j][k];
					if (building[i][j][k] == 'S') {
						x = i;
						y = j;
						z = k;
					}
					if (building[i][j][k] == 'E') {
						fx = i;
						fy = j;
						fz = k;
					}
				}
			}
		}

		if (x == fx && y == fy && z == fz) {
			cout << "Escaped in 0 minute(s)." << '\n';
			continue;
		}
		bfs(x, y, z);
		if (visited[fx][fy][fz] == 0) cout << "Trapped!" << '\n';
		else cout << "Escaped in " << visited[fx][fy][fz] - 1 << " minute(s).\n";
	}

	return 0;
}