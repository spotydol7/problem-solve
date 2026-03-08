#include <bits/stdc++.h>
using namespace std;

bool isZero(vector<int> &v) {
	for (int n : v) {
		if (n != 0) return false;
	}
	return true;
}

int main() {
	int N;
	cin >> N;

	vector<int> b;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		b.push_back(temp);
	}

	int ans = 0;

	while (true) {
		for (int i = 0; i < N; i++) {
			if (b[i] % 2 == 1) {
				ans++;
				b[i]--;
			}
		}

		if (isZero(b)) break;

		for (int i = 0; i < N; i++) {
			b[i] /= 2;
		}
		ans++;
	}

	cout << ans << '\n';

	return 0;
}