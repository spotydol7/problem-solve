#include <iostream>
#include <algorithm>
typedef long long ll;

using namespace std;

ll n, m, v[1000000], temp;

bool Check(const int mid) {
	ll sum = 0; 
	for (int i = 0; i < n; i++) {
		if (v[i] > mid) sum += v[i] - mid;
	}
	return sum >= m;
}

int main()
{

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v, v + n);

	int begin = 0;
	int end = 1e9;
	while (begin + 1 < end) {
		int mid = (begin + end) / 2;
		if (Check(mid)) begin = mid;
		else end = mid;
	}

	cout << begin << endl;

	return 0;
}