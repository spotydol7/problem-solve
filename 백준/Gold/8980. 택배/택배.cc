#include <bits/stdc++.h>
using namespace std;

int town[2002];

bool compare(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b) {
	if (a.first.second == b.first.second) return a.first.first < b.first.first;
	else return a.first.second < b.first.second;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, c;
	cin >> n >> c;
	
	int m;
	cin >> m;
	
	vector<pair<pair<int, int>, int>> v;
	for (int i = 0; i < m; i++) {
		int from, to, box;
		cin >> from >> to >> box;
		v.push_back({ {from, to}, box });
	}

	sort(v.begin(), v.end(), compare);

	int ans = 0;
	
	for (int i = 0; i < v.size(); i++) {
		int from = v[i].first.first;
		int to = v[i].first.second;
		int boxes = v[i].second;

		int maxBox = 0;
		for (int j = from; j < to; j++) {
			maxBox = town[j] > maxBox ? town[j] : maxBox;
		}

		int cap = min(boxes, c - maxBox);
		for (int j = from; j < to; j++) {
			town[j] += cap;
		}
		ans += cap;
	}

	cout << ans;
	
	return 0;
}

/*
4 40
6
3 4 20
1 2 10
1 3 20
1 4 30
2 3 10
2 4 20

ans : 70

정렬 후 (도착지 기준):
1 2 10
1 3 20
2 3 10
1 4 30
2 4 20
3 4 20

6 60
5
1 2 30
2 5 70
5 6 60
3 4 40
1 6 40

ans : 150

정렬 후 (도착지 기준):
1 2 30
3 4 40
2 5 70
1 6 40
5 6 60

*/