#include<bits/stdc++.h>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		int beg = 0;
		int end = n - 1;
		while (beg < end) {
			if (beg == i) {
				beg++;
				continue;
			}
			if (end == i) {
				end--;
				continue;
			}

			if (v[beg] + v[end] == v[i]) {
				ans++;
				break;
			}
			else if (v[beg] + v[end] < v[i]) beg++;
			else if (v[beg] + v[end] > v[i]) end--;
		}
	}

	cout << ans << '\n';

	return 0;
}