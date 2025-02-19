#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int s, t;
		cin >> s >> t;
		v.push_back({ s, t });
	}

	// S에 시작해서 T에 끝나는 N개의 수업이 주어지는데, 최소의 강의실을 사용해서 모든 수업을 가능하게 해야 한다. 참고로, 수업이 끝난 직후에 다음 수업을 시작할 수 있다.
	sort(v.begin(), v.end());

	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(v[0].second);

	for (int i = 1; i < v.size(); i++) {
		if (v[i].first >= pq.top()) {
			pq.pop();
			pq.push(v[i].second);
		}
		else {
			pq.push(v[i].second);
		}
	}
	int ans = pq.size();
	cout << ans;

	return 0;
}