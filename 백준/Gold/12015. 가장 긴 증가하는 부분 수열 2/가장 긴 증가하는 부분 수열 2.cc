#include <bits/stdc++.h>
using namespace std;

int arr[1000001];
int lis[1000001];
vector<int> v;

int binSearch(int st, int en, int target) {
	int mid;
	while (st < en) {
		mid = (st + en) / 2;
		if (lis[mid] < target) {
			st = mid + 1;
		}
		else en = mid;
	}
	return en;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	lis[0] = v[0];
	int last = 0;

	for (int i = 0; i < n; i++) {
		if (v[i] > lis[last]) {
			lis[++last] = v[i];
		}
		else {
			int idx = binSearch(0, last, v[i]);
			lis[idx] = v[i];
		}
	}

	cout << last + 1;

	return 0;
}

/*

배열의 각 요소를 순회한다. 이때, 배열의 각 요소를 lis 배열에 담는데, lis 배열에는 작은 순서대로만 들어가야 한다.

따라서 lis 배열의 가장 마지막 요소와 배열의 요소를 비교하면 된다.

만약 lis 배열의 최댓값보다 크다면 해당 요소를 lis 배열의 마지막에 추가시켜주면 된다.

*/