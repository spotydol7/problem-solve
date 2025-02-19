#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> v;
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x, y });
	}

	sort(v.begin(), v.end()); // 선 긋는 시작점 기준 오름차순 정렬
	
	int start = v[0].first;
	int end = v[0].second;
	// pq.push(v[0].second);
	int ans = 0;
	for (int i = 1; i < n; i++) {
		if (v[i].first > end) {
			ans += end - start;
			start = v[i].first;
			end = v[i].second;
		}
		else if (v[i].first <= end && v[i].second > end) {
			end = v[i].second;
		}
	}

	ans += end - start;
	cout << ans;

	return 0;
}