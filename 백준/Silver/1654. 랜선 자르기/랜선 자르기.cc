#include <iostream>
#include <vector>
using namespace std;

int main()
{
	long long lan[10001];
	long long k, n, sum = 0, temp;
	long long right = 0, left = 1;
	long long mid;
	long long max = 0;

	cin >> k >> n;

	for (int i = 0; i < k; i++) {
		cin >> temp;
		sum += temp;
		lan[i] = temp;
		if (right < temp) right = temp;
	}

	while (left <= right) {
		sum = 0;
		mid = (left + right) / 2;
		for (int j = 0; j < k; j++) {
			sum += lan[j] / mid;
		}
		if (sum < n) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
			if (max < mid) max = mid;
		}
	}

	cout << max;

	return 0;
}