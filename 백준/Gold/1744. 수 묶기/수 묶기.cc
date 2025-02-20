#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	
	vector<int> minus;
	vector<int> plus;

	int ones = 0;
	int zeros = 0;
	
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (temp == 1) ones++;
		else if (temp == 0) zeros++;
		else if (temp < 0) minus.push_back(temp);
		else plus.push_back(temp);
	}
	
	sort(plus.begin(), plus.end());
	sort(minus.begin(), minus.end());

	long long ans = 0;
	for (int i = plus.size() - 1; i >= 0; i -= 2) {
		if (i - 1 >= 0) {
			ans += plus[i] * plus[i - 1];
		}
	}
	if (plus.size() % 2 == 1) ans += plus[0];
	ans += ones;

	for (int i = 0; i < minus.size(); i += 2) {
		if (i + 1 < minus.size()) {
			ans += minus[i] * minus[i + 1];
		}
	}
	if (minus.size() % 2 == 1 && zeros == 0) ans += minus[minus.size() - 1];

	cout << ans;

	return 0;
}