#include <bits/stdc++.h>
using namespace std;

long long p[101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int test_case;
	cin >> test_case;
	for (int t = 0; t < test_case; t++) {
		int n;
		cin >> n;
		
		p[1] = 1;
		p[2] = 1;
		p[3] = 1;
		p[4] = 2;
		p[5] = 2;

		if (n > 5) {
			for (int i = 6; i <= n; i++) {
				p[i] = p[i - 1] + p[i - 5];
			}
		}

		cout << p[n] << '\n';
	}

	return 0;
}