#include <bits/stdc++.h>
using namespace std;

int solve(int n, int r, int c) {
	if (n == 1) {
		if (r == 0 && c == 0) {
			return 0;
		}
		if (r == 0 && c == 1) {
			return 1;
		}
		if (r == 1 && c == 0) {
			return 2;
		}
		if (r == 1 && c == 1) {
			return 3;
		}
	}
	else {
		int a = pow(2, n - 1);
		int b = pow(a, 2);
		if (r <= a - 1 && c <= a - 1) {
			return solve(n - 1, r, c);
		}
		if (r <= a - 1 && c > a - 1) {
			return b + solve(n - 1, r, c - a);
		}
		if (r > a - 1 && c <= a - 1) {
			return  2 * b + solve(n - 1, r - a, c);
		}
		if (r > a - 1 && c > a - 1) {
			return 3 * b + solve(n - 1, r - a, c - a);
		}
	}
}

int main() {
	int n, r, c;
	cin >> n >> r >> c;

	int ans = solve(n, r, c);
	cout << ans << '\n';

	return 0;
}