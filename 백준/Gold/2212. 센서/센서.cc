#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	if (N == 0 || K >= N) {
		cout << 0 << '\n';
		return 0;
	}

	vector<int> sensors;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		sensors.push_back(temp);
	}

	sort(sensors.begin(), sensors.end());

	vector<int> diff;
	for (int i = 1; i < sensors.size(); i++) {
		diff.push_back(sensors[i] - sensors[i - 1]);
	}

	sort(diff.begin(), diff.end());

	int ans = 0;
	for (int i = 0; i < diff.size() - K + 1; i++) {
		ans += diff[i];
	}
	cout << ans;

	return 0;
}