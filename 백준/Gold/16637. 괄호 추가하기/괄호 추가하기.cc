#include <bits/stdc++.h>
using namespace std;

int n;
int ans = INT_MIN;
vector<int> nums;
vector<char> ops;
string str;

int calc(char op, int a, int b) {
	if (op == '+') return a + b;
	else if (op == '-') return a - b;
	else if (op == '*') return a * b;
}

void put(int depth, int num) {
	if (depth == nums.size() - 1) {
		ans = num >= ans ? num : ans;
		return;
	}

	put(depth + 1, calc(ops[depth], num, nums[depth + 1]));

	if (depth + 2 <= nums.size() - 1) {
		int temp = calc(ops[depth + 1], nums[depth + 1], nums[depth + 2]);
		put(depth + 2, calc(ops[depth], num, temp));
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	cin >> str;
	for (int i = 0; i < n; i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			nums.push_back(str[i] - '0');
		}
		else ops.push_back(str[i]);
	}

	put(0, nums[0]);
	cout << ans << '\n';

	return 0;
}