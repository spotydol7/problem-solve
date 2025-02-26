#include <bits/stdc++.h>

using namespace std;

int arr[1000001];
vector<pair<int, int>> DP(1000001); // 계산 횟수, 이전 수 쌍

int main() {
	int n;
	cin >> n;

	arr[1] = 0;

	DP[1].first = 0;
	DP[1].second = 0;

	vector<int> ans;
	ans.push_back(n);

	for (int i = 2; i <= n; i++) {
		arr[i] = arr[i - 1] + 1;
		DP[i].first = DP[i - 1].first + 1;
		DP[i].second = i - 1;

		if (i % 2 == 0) {
			arr[i] = min(arr[i / 2] + 1, arr[i]);
			
			if (DP[i / 2].first + 1 <= DP[i].first) {
				DP[i].first = DP[i / 2].first + 1;
				DP[i].second = i / 2;
			}
		}
		if (i % 3 == 0) {
			arr[i] = min(arr[i / 3] + 1, arr[i]);

			if (DP[i / 3].first + 1 <= DP[i].first) {
				DP[i].first = DP[i / 3].first + 1;
				DP[i].second = i / 3;
			}

		}
	}

	int temp = n;
	while (1) {
		temp = DP[temp].second;
		//cout << "TEMP : " << temp << endl;
		if (temp == 0) break;
		ans.push_back(temp);
	}

	cout << DP[n].first << '\n';
	for (auto iter = ans.begin(); iter != ans.end(); iter++) {
		cout << *iter << ' ';
	}

	return 0;
}

/*
642
10
642 641 640 320 160 80 40 20 10 9 3 1

ans: 642 321 320 160 80 40 20 10 9 3 1
*/