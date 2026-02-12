#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> v;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	vector<int> sum;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sum.push_back(v[i] + v[j]);
		}
	}

	sort(v.begin(), v.end());
	sort(sum.begin(), sum.end());

	for (int i = N - 1; i >= 0; i--) {
		for (int j = N - 1; j >= 0; j--) {
			bool ans = binary_search(sum.begin(), sum.end(), v[i] - v[j]);
			if (ans) {
				cout << v[i] << '\n';
				return 0;
			}
		}
	}

	return 0;
}