#include <bits/stdc++.h>
using namespace std;

int dp[201];

int main() {
	int N;
	cin >> N;

	vector<int> jammin; //잼민이 ㅋㅋ
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		jammin.push_back(temp);
	}

	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (jammin[i] > jammin[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int maximum = -1;
	for (int i = 0; i < N; i++) {
		maximum = max(dp[i], maximum);
	}

	cout << N - maximum;

	return 0;
}