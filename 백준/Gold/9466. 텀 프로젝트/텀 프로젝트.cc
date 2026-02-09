#include <bits/stdc++.h>
using namespace std;

int n;
int state[100001];
int board[100001];

const int NOT_VISITED = 0;
const int CYCLE_IN = -1;

void run(int x) {
	int cur = x;
	while (1) {
		state[cur] = x;
		cur = board[cur];
		// 이번 방문에서 지나간 학생에 도달했을 경우
		if (state[cur] == x) {
			while (state[cur] != CYCLE_IN) {
				state[cur] = CYCLE_IN;
				cur = board[cur];
			}
			return;
		}
		// 이전의 방문에서 지나간 학생에 도달했을 경우
		else if (state[cur] != 0) return;
	}
}

int main() {
	int test_case;
	cin >> test_case;

	while (test_case--) {
		cin >> n;
		fill(state + 1, state + n + 1, 0);
		
		for (int i = 1; i <= n; i++)
			cin >> board[i];
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (state[i] == NOT_VISITED) run(i);
		}

		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (state[i] != CYCLE_IN) cnt++;
		}
		cout << cnt << '\n';
	}

	return 0;
}