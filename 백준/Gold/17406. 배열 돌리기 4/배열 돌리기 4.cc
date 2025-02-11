#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int ans = INT_MAX;

int arr[51][51];
int copy_arr[51][51];
int order[7];
vector<pair<pair<int, int>, int>> v;

void calc() {
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < m; j++) {
			cnt += copy_arr[i][j];
		}
		ans = min(ans, cnt);
	}
}

void rotate(int r, int c, int s) {
	int top = r - s - 1;
	int left = c - s - 1;
	int bottom = r + s - 1;
	int right = c + s - 1;

	int temp = copy_arr[top][left];

	// 왼쪽 열 위로 이동
	for (int i = top; i < bottom; i++) {
		copy_arr[i][left] = copy_arr[i + 1][left];
	}

	// 아래쪽 행 왼쪽으로 이동
	for (int j = left; j < right; j++) {
		copy_arr[bottom][j] = copy_arr[bottom][j+1];
	}

	// 오른쪽 열 아래로 이동
	for (int i = bottom; i > top; i--) {
		copy_arr[i][right] = copy_arr[i-1][right];
	}

	// 위쪽 행 오른쪽으로 이동
	for (int j = right; j > left+1; j--) {
		copy_arr[top][j] = copy_arr[top][j-1];
	}

	copy_arr[top][left + 1] = temp;
}


void ordering(int level) {
	if (level == k) {
		// 배열 복붙
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				copy_arr[i][j] = arr[i][j];
			}
		}

		for (int i = 0; i < k; i++) {
			int r = v[order[i] - 1].first.first;
			int c = v[order[i] - 1].first.second;
			int s = v[order[i] - 1].second;
			for (int j = 1; j <= s; j++) {
				rotate(r, c, j);
			}
		}
		calc();
	}
	else {
		for (int i = 0; i < k; i++) {
			if (order[i] == 0) {
				order[i] = level + 1;
				ordering(level + 1);
				order[i] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		int r, c, s;
		cin >> r >> c >> s;
		v.push_back({ {r, c}, s });
	}

	ordering(0);

	cout << ans;

	return 0;
}