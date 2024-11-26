#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<pair<int, int>> physical;
	vector<int> rank;
	int n, x, y;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		physical.push_back(make_pair(x, y));
	}

	for (auto iter = physical.begin(); iter != physical.end(); iter++) {
		int cnt = 1;
		for (auto jter = physical.begin(); jter != physical.end(); jter++) {
			if ((*iter).first < (*jter).first && (*iter).second < (*jter).second) {
				cnt++;
			}
		}
		rank.push_back(cnt);
	}

	for (auto iter = rank.begin(); iter != rank.end(); iter++) {
		cout << *iter << ' ';
	}

	return 0;
}