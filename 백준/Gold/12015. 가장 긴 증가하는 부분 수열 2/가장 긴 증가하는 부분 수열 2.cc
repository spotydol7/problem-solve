#include <bits/stdc++.h>
using namespace std;

int lis[1000001]; // LIS 저장할 배열
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

	lis[0] = v[0]; // 일단 첫 원소 넣기
	int last = 0; // LIS 배열의 마지막 idx

	for (int i = 0; i < n; i++) {
		if (v[i] > lis[last]) { // 벡터의 다음 원소가 LIS의 마지막 보다 크면
			lis[++last] = v[i]; // LIS의 마지막이 가장 큰 원소이므로 그냥 그 뒤에 추가
		}
		else { // 벡터의 다음 원소가 LIS 마지막보다 작으면
			int idx = binSearch(0, last, v[i]); // LIS배열에서 이분탐색해서 v[i] 들어갈 자리 찾고 넣기
			lis[idx] = v[i];
		}
	}

	cout << last + 1;

	return 0;
}