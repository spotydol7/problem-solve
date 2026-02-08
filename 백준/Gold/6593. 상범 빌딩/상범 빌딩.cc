#include <bits/stdc++.h>
using namespace std;

int dr[6] = { 1, -1, 0, 0, 0, 0 };
int dc[6] = { 0, 0, 1, -1, 0, 0 };
int dl[6] = { 0, 0, 0, 0, 1, -1 };

int main() {

	while (true) {
		string board[31][31];
		int step[31][31][31];
		bool escape = false;

		memset(step, -1, sizeof(step));
		queue<pair<pair<int, int>, int>> q;

		int L, R, C;
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) break;

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				cin >> board[i][j];
				for (int k = 0; k < C; k++) {
					if (board[i][j][k] == 'S') {
						q.push({ {i, j}, k });
						step[i][j][k] = 0;
					}
				}
			}
		}

		while (!q.empty()) {
			auto cur = q.front();
			q.pop();
			int cur_l = cur.first.first;
			int cur_r = cur.first.second;
			int cur_c = cur.second;

			if (board[cur_l][cur_r][cur_c] == 'E') {
				escape = true;
				cout << "Escaped in " << step[cur_l][cur_r][cur_c] << " minute(s)." << '\n';
				break;
			}

			for (int i = 0; i < 6; i++) {
				int nl = cur_l + dl[i];
				int nr = cur_r + dr[i];
				int nc = cur_c + dc[i];

				if (nl < 0 || nl >= L || nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
				if (board[nl][nr][nc] == '#' || step[nl][nr][nc] >= 0) continue;

				q.push({ {nl, nr}, nc });
				step[nl][nr][nc] = step[cur_l][cur_r][cur_c] + 1;
			}
		}

		if (!escape) cout << "Trapped!" << '\n';
	}

	return 0;
}