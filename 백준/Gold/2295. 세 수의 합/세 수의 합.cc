#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;
vector<int> sums;

int binarySearch(int num, int start, int end) {
	int mid;

	while (start <= end) {
		mid = (start + end) / 2;
		if (num == sums[mid])
			return mid;
		else if (num < sums[mid])
			end = mid - 1;
		else if (num > sums[mid])
			start = mid + 1;
	}
	return -1;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			sums.push_back(arr[i] + arr[j]);
		}
	}

	sort(sums.begin(), sums.end());

	/*
	cout << "sums : " << endl;
	for (int i = 0; i < sums.size(); i++) {
		cout << sums[i] << ' ';
	}
	cout << endl;
	*/

	for (int i = n - 1; i >= 0; i--) {
		for (int j = i; j >= 0; j--) {
			int num = arr[i] - arr[j];

			// cout << "arr[i] - arr[j] : " << num << '\n';
			if (binarySearch(num, 0, sums.size() - 1) != -1) {
				cout << arr[i];
				return 0;
			}
		}
	}

	return 0;
}