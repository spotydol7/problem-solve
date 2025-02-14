#include <bits/stdc++.h>
using namespace std;

int n, m;
int ans = INT_MAX;
int board[9][9];
int copy_board[9][9];
vector<pair<pair<int, int>, pair<int, int>>> camera; // 좌표1, 좌표2, 방향, 카메라 종류

void record(int cam, int dir, int r, int c) {
	int dr[4] = { 0, 0, 1, -1 };
	int dc[4] = { 1, -1, 0, 0 }; // 동 서 남 북

	if (cam == 1) { // 한쪽만
		int nr = 0;
		int nc = 0;
		int step = 1;
		while (1) {
			nr = r + dr[dir] * step;
			nc = c + dc[dir] * step;
			if (nr >= n || nr < 0 || nc >= m || nc < 0) break;
			if (copy_board[nr][nc] == 6) break;
			copy_board[nr][nc] = -1;
			step++;
		}
	}
	else if (cam == 2) { // 한쪽과 그 반대쪽만
		int step = 1;
		while (1) {
			int nr = r + dr[dir] * step;
			int nc = c + dc[dir] * step;
			if (nr >= n || nr < 0 || nc >= m || nc < 0) break;
			if (copy_board[nr][nc] == 6) break;
			copy_board[nr][nc] = -1;
			step++;
		}
		step = 1;
		while (1) {
			int nr = r + dr[dir] * step * (-1);
			int nc = c + dc[dir] * step * (-1);
			if (nr >= n || nr < 0 || nc >= m || nc < 0) break;
			if (copy_board[nr][nc] == 6) break;
			copy_board[nr][nc] = -1;
			step++;
		}
	}
	else if (cam == 3) { // 90도 방향
		if (dir == 0) {
			int step = 1;
			while (1) { // 바라보는 방향
				int nr = r + dr[dir] * step;
				int nc = c + dc[dir] * step;
				if (nr >= n || nr < 0 || nc >= m || nc < 0) break;
				if (copy_board[nr][nc] == 6) break;
				copy_board[nr][nc] = -1;
				step++;
			}
			step = 1;
			while (1) { // 그 왼쪽
				int nr = r + dr[3] * step;
				int nc = c + dc[3] * step;
				if (nr >= n || nr < 0 || nc >= m || nc < 0) break;
				if (copy_board[nr][nc] == 6) break;
				copy_board[nr][nc] = -1;
				step++;
			}
		}
		else if (dir == 1) {
			int step = 1;
			while (1) { // 바라보는 방향
				int nr = r + dr[dir] * step;
				int nc = c + dc[dir] * step;
				if (nr >= n || nr < 0 || nc >= m || nc < 0) break;
				if (copy_board[nr][nc] == 6) break;
				copy_board[nr][nc] = -1;
				step++;
			}
			step = 1;
			while (1) { // 그 왼쪽
				int nr = r + dr[2] * step;
				int nc = c + dc[2] * step;
				if (nr >= n || nr < 0 || nc >= m || nc < 0) break;
				if (copy_board[nr][nc] == 6) break;
				copy_board[nr][nc] = -1;
				step++;
			}
		}
		else if (dir == 2) {
			int step = 1;
			while (1) { // 바라보는 방향
				int nr = r + dr[dir] * step;
				int nc = c + dc[dir] * step;
				if (nr >= n || nr < 0 || nc >= m || nc < 0) break;
				if (copy_board[nr][nc] == 6) break;
				copy_board[nr][nc] = -1;
				step++;
			}
			step = 1;
			while (1) { // 그 왼쪽
				int nr = r + dr[0] * step;
				int nc = c + dc[0] * step;
				if (nr >= n || nr < 0 || nc >= m || nc < 0) break;
				if (copy_board[nr][nc] == 6) break;
				copy_board[nr][nc] = -1;
				step++;
			}
		}
		else if (dir == 3) {
			int step = 1;
			while (1) { // 바라보는 방향
				int nr = r + dr[dir] * step;
				int nc = c + dc[dir] * step;
				if (nr >= n || nr < 0 || nc >= m || nc < 0) break;
				if (copy_board[nr][nc] == 6) break;
				copy_board[nr][nc] = -1;
				step++;
			}
			step = 1;
			while (1) { // 그 왼쪽
				int nr = r + dr[1] * step;
				int nc = c + dc[1] * step;
				if (nr >= n || nr < 0 || nc >= m || nc < 0) break;
				if (copy_board[nr][nc] == 6) break;
				copy_board[nr][nc] = -1;
				step++;
			}
		}
	}
	else if (cam == 4) { // 3방향
		if (dir == 0) {
			int step = 1;
			while (1) { // 바라보는 방향
				int nr = r + dr[dir] * step;
				int nc = c + dc[dir] * step;
				if (nr >= n || nr < 0 || nc >= m || nc < 0) break;
				if (copy_board[nr][nc] == 6) break;
				copy_board[nr][nc] = -1;
				step++;
			}
			step = 1;
			while (1) { // 그 왼쪽
				int nr = r + dr[3] * step;
				int nc = c + dc[3] * step;
				if (nr >= n || nr < 0 || nc >= m || nc < 0) break;
				if (copy_board[nr][nc] == 6) break;
				copy_board[nr][nc] = -1;
				step++;
			}
			step = 1;
			while (1) { // 그 오른쪽
				int nr = r + dr[2] * step;
				int nc = c + dc[2] * step;
				if (nr >= n || nr < 0 || nc >= m || nc < 0) break;
				if (copy_board[nr][nc] == 6) break;
				copy_board[nr][nc] = -1;
				step++;
			}
		}
		else if (dir == 1) {
			int step = 1;
			while (1) { // 바라보는 방향
				int nr = r + dr[dir] * step;
				int nc = c + dc[dir] * step;
				if (nr >= n || nr < 0 || nc >= m || nc < 0) break;
				if (copy_board[nr][nc] == 6) break;
				copy_board[nr][nc] = -1;
				step++;
			}
			step = 1;
			while (1) { // 그 왼쪽
				int nr = r + dr[2] * step;
				int nc = c + dc[2] * step;
				if (nr >= n || nr < 0 || nc >= m || nc < 0) break;
				if (copy_board[nr][nc] == 6) break;
				copy_board[nr][nc] = -1;
				step++;
			}
			step = 1;
			while (1) { // 그 오른쪽
				int nr = r + dr[3] * step;
				int nc = c + dc[3] * step;
				if (nr >= n || nr < 0 || nc >= m || nc < 0) break;
				if (copy_board[nr][nc] == 6) break;
				copy_board[nr][nc] = -1;
				step++;
			}
		}
		else if (dir == 2) {
			int step = 1;
			while (1) { // 바라보는 방향
				int nr = r + dr[dir] * step;
				int nc = c + dc[dir] * step;
				if (nr >= n || nr < 0 || nc >= m || nc < 0) break;
				if (copy_board[nr][nc] == 6) break;
				copy_board[nr][nc] = -1;
				step++;
			}
			step = 1;
			while (1) { // 그 왼쪽
				int nr = r + dr[0] * step;
				int nc = c + dc[0] * step;
				if (nr >= n || nr < 0 || nc >= m || nc < 0) break;
				if (copy_board[nr][nc] == 6) break;
				copy_board[nr][nc] = -1;
				step++;
			}
			step = 1;
			while (1) { // 그 오른쪽
				int nr = r + dr[1] * step;
				int nc = c + dc[1] * step;
				if (nr >= n || nr < 0 || nc >= m || nc < 0) break;
				if (copy_board[nr][nc] == 6) break;
				copy_board[nr][nc] = -1;
				step++;
			}
		}
		else if (dir == 3) {
			int step = 1;
			while (1) { // 바라보는 방향
				int nr = r + dr[dir] * step;
				int nc = c + dc[dir] * step;
				if (nr >= n || nr < 0 || nc >= m || nc < 0) break;
				if (copy_board[nr][nc] == 6) break;
				copy_board[nr][nc] = -1;
				step++;
			}
			step = 1;
			while (1) { // 그 왼쪽
				int nr = r + dr[0] * step;
				int nc = c + dc[0] * step;
				if (nr >= n || nr < 0 || nc >= m || nc < 0) break;
				if (copy_board[nr][nc] == 6) break;
				copy_board[nr][nc] = -1;
				step++;
			}
			step = 1;
			while (1) { // 그 오른쪽
				int nr = r + dr[1] * step;
				int nc = c + dc[1] * step;
				if (nr >= n || nr < 0 || nc >= m || nc < 0) break;
				if (copy_board[nr][nc] == 6) break;
				copy_board[nr][nc] = -1;
				step++;
			}
		}
	}
	else { // 4방향 다
		for (int i = 0; i < 4; i++) {
			int step = 1;
			while (1) {
				int nr = r + dr[i] * step;
				int nc = c + dc[i] * step;
				if (nr >= n || nr < 0 || nc >= m || nc < 0) break;
				if (copy_board[nr][nc] == 6) break;
				copy_board[nr][nc] = -1;
				step++;
			}
		}
	}
}

void backtracking(int level) {
	if (level == camera.size()) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				copy_board[i][j] = board[i][j];
			}
		}

		for (int i = 0; i < camera.size(); i++) {
			int cam = camera[i].second.second;
			int dir = camera[i].second.first;
			int r = camera[i].first.first;
			int c = camera[i].first.second;
			// << "dir : " << dir << ' ';
			record(cam, dir, r, c);
		}
		//cout << '\n';

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (copy_board[i][j] == 0) cnt++;
			}
		}
		ans = cnt < ans ? cnt : ans; // 최솟값 갱신
	}
	else {
		for (int i = 0; i < 4; i++) { // 카메라 개수, 4개 방향 중복조합으로 ( 동 서 남 북 0 1 2 3 )
			camera[level].second.first = i;
			backtracking(level + 1);
		}
	}
}

int main() {
	/*
	1번 CCTV는 한 쪽 방향만 감시할 수 있다. 
	2번과 3번은 두 방향을 감시할 수 있는데, 2번은 감시하는 방향이 서로 반대방향이어야 하고, 
	3번은 직각 방향이어야 한다. 
	4번은 세 방향, 5번은 네 방향을 감시할 수 있다.
	*/

	/*
	input:
	5 5
	1 0 0 0 1
	0 1 0 1 0
	0 0 0 0 0
	0 1 0 1 0
	1 0 0 0 1
	output: 4
	answer: 1
	*/

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] >= 1 && board[i][j] <= 5) {
				camera.push_back({ {i, j}, {0, board[i][j]} });
			}
		}
	}

	backtracking(0);
	cout << ans;

	return 0;
}