#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[8];

void backtracking(int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	
	for (int i = 1; i <= n; i++) {
		arr[depth] = i;
		backtracking(depth + 1);
	}
}

int main() {
	cin >> n >> m;
	
	backtracking(0);

	return 0;
}