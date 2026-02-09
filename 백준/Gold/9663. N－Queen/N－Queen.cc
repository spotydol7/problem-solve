#include <bits/stdc++.h>
using namespace std;

int n;
int ans = 0;
int column[16];

bool isPossible(int num) {
	for (int i = 0; i < num; i++) {
		if (column[num] == column[i] || abs(num - i) == abs(column[num] - column[i]))
			return false;
	}
	return true;
}

void dfs(int depth) {
	if (depth == n) {
		ans++;
		return;
	}
	
	for (int i = 0; i < n; i++) {
		column[depth] = i;
		if (isPossible(depth))
			dfs(depth + 1);
	}
}

int main() {
	cin >> n;
	dfs(0);
	cout << ans << '\n';

	return 0;
}