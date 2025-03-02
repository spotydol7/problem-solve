#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> nums;
int arr[9];

void backtracking(int start, int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	int flag = 0;
	for (int i = start; i < n; i++) {
		if (flag != nums[i]) {
			arr[depth] = nums[i];
			flag = nums[i];
			backtracking(i, depth + 1);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}

	sort(nums.begin(), nums.end());

	backtracking(0, 0);

	return 0;
}