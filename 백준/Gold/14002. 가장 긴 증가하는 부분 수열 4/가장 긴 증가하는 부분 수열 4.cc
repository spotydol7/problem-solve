#include <bits/stdc++.h>
using namespace std;

int lis[1000001];
int dpIdx[1000001];
int parent[1000001]; // 이전원소 인덱스 ㅇㅇ

int binSearch(int st, int en, int target) {
	int mid;
	while (st < en) {
		mid = (st + en) / 2;
		if (lis[mid] < target)
			st = mid + 1;
		else
			en = mid;
	}
	return en;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	lis[0] = v[0];
	dpIdx[0] = 0;
	parent[0] = -1; // 이전 없으니까 -1
	int last = 0;

	for (int i = 1; i < n; i++) {
		if (v[i] > lis[last]) {
			last++;
			lis[last] = v[i];
			dpIdx[last] = i;
			parent[i] = dpIdx[last - 1]; // 이전 인덱스 기록
		}
		else {
			int idx = binSearch(0, last, v[i]); // lis 배열에서 v[i]가 들어갈 자리 찾기
			lis[idx] = v[i];
			dpIdx[idx] = i;
			// 만약 idx가 0이면 이전 원소 없음, 아님 이전원소 dpIdx[idx-1]
			parent[i] = (idx == 0) ? -1 : dpIdx[idx - 1];
		}
	}

	cout << last + 1 << "\n";

	vector<int> sequence;
	int cur = dpIdx[last];
	while (cur != -1) {
		sequence.push_back(v[cur]);
		cur = parent[cur];
	}
	reverse(sequence.begin(), sequence.end());


	for (int num : sequence)
		cout << num << " ";

	return 0;
}
