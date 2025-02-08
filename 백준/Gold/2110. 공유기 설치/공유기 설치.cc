#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int binSearch(int n, int c) {
	int left = 0;
	int right = v[n - 1] - v[0] + 1;

	int result;

	while (left <= right) {
		int cnt = 1;
		int mid = (left + right) / 2;

		int start = v[0];

		for (int i = 1; i < n; i++) {
			int end = v[i];

			if (end - start >= mid) {
				cnt++;
				start = end;
			}
		}

		if (cnt >= c) {
			result = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, c;
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());
	int ans = binSearch(n, c);
	cout << ans;


	return 0;
}