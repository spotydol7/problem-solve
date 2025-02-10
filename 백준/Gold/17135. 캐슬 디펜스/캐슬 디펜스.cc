#include <bits/stdc++.h>
using namespace std;

void kill();
void putArcher(int arch);
void moveEnemy();
int getDist(int a, int b, int c, int d);

int n, m, d;
int killCnt, ans;
bool isEnded = false;
int arr[16][16];
int copy_arr[16][16];
int killed[16][16];
int visited[16][16];
int archer[3];
int dr[3] = { 0, -1, 0 };
int dc[3] = { -1, 0, 1 };

/*
4 4 3
0 1 1 0
0 0 1 1
1 0 1 0
1 1 1 0
ans : 8 but prints 9
*/

void kill() {
	// 중복된 좌표가 저장되지 않도록 set 사용 (pair의 첫번째는 행, 두번째는 열)
	set<pair<int, int>> targets;

	// 3명의 궁수에 대해 각각 공격할 목표를 선정
	for (int k = 0; k < 3; k++) {
		int archerCol = archer[k];  // 궁수의 열 위치
		int target_r = -1, target_c = -1;
		int min_distance = d + 1;     // d보다 큰 초기값 설정

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (copy_arr[i][j] == 1) { // 적이 있는 경우
					int distance = getDist(n, archerCol, i, j);
					if (distance <= d) { // 공격 가능 범위 내라면
						// 더 짧은 거리를 발견하거나 거리가 같을 경우 왼쪽에 있는 적 선택
						if (distance < min_distance || (distance == min_distance && j < target_c)) {
							min_distance = distance;
							target_r = i;
							target_c = j;
						}
					}
				}
			}
		}
		// 해당 궁수가 공격할 목표가 존재하면 set에 추가
		if (target_r != -1) {
			targets.insert({ target_r, target_c });
		}
	}

	// 동시 공격 구현 (set으로 중복제거)
	for (auto &target : targets) {
		if (copy_arr[target.first][target.second] == 1) {  // 이미 제거되지 않았다면
			copy_arr[target.first][target.second] = 0;
			killCnt++;
		}
	}
}

void putArcher(int arch) {
	if (arch == 3) {
		killCnt = 0;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				copy_arr[i][j] = arr[i][j];
			}
		}

		isEnded = false;
		while (!isEnded) {
			memset(killed, 0, sizeof(killed));
			kill();
			
			moveEnemy();
			
		}
		ans = max(ans, killCnt);
	}
	else {
		for (int i = 0; i < m; i++) {
			if (copy_arr[n][i] == 0) {
				copy_arr[n][i] = 2; // 궁수 : 2로 표시
				archer[arch] = i;
				putArcher(arch + 1);
				copy_arr[n][i] = 0;
			}
		}
	}
}

void moveEnemy() {
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < m; j++) {
			if (copy_arr[i][j] == 1) {
				copy_arr[i][j] = 0;
				if (i + 1 < n) copy_arr[i + 1][j] = 1;
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cnt += copy_arr[i][j];
		}
	}
	if (cnt > 0) isEnded = false;
	else {
		isEnded = true;
	}
}

int getDist(int a, int b, int c, int d) {
	return abs(a - c) + abs(b - d);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	putArcher(0);

	cout << ans;

	return 0;
}