#include <bits/stdc++.h>
using namespace std;

int n;
int ans[17];
vector<pair<int, int>> tp;

void counseling() { // DP
	for (int i = n; i > 0; i--) {
		if (i + tp[i - 1].first - 1 > n) {
			ans[i] = ans[i + 1];
		}
		else {
			ans[i] = max(ans[i + 1], ans[i + tp[i - 1].first] + tp[i - 1].second);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t, p; //상담을 완료하는데 걸리는 기간 T와 상담을 했을 때 받을 수 있는 금액 P
		cin >> t >> p;
		tp.push_back({ t, p }); // tp는 idx 0부터 시작
	}

	counseling();

	cout << ans[1];

	return 0;
}