#include <bits/stdc++.h>
using namespace std;

int n, s;
vector<int> seq;

int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		seq.push_back(temp);
	}

	int st = 0;
	int en = 0;
	int sum = seq[0];
	int ans = 100001;

	while (st <= en && en < n) {
		if (sum < s) {
			sum += seq[++en];
		}
		else {
			ans = min(ans, en - st + 1);
			sum -= seq[st++];
		}
	}

	if (ans > n) cout << 0;
	else cout << ans;

	return 0;
}