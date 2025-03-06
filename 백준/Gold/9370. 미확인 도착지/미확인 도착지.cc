#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int n, m, t;
int start, g, h;
int dist[2001];
vector<pair<int, int>> adjacent[2001];

struct compare {
	bool operator() (pair<int, int> a, pair<int, int> b) {
		if (a.second == b.second) return a.first > b.first;
		return a.second > b.second;
	}
};

void dijkstra(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

	for (int i = 0; i <= n; i++) {
		dist[i] = INF;
	}

	dist[start] = 0;
	pq.push({ start, 0 });

	while (!pq.empty()) {
		int curNode = pq.top().first;
		int weightSum = pq.top().second;
		pq.pop();

		if (dist[curNode] < weightSum) continue;

		for (int i = 0; i < adjacent[curNode].size(); i++) {
			int nextNode = adjacent[curNode][i].first;
			int nextWeight = adjacent[curNode][i].second;

			if (dist[nextNode] > nextWeight + weightSum) {
				dist[nextNode] = nextWeight + weightSum;
				pq.push({ nextNode, dist[nextNode] });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m >> t; // 각각 교차로, 도로, 목적지 후보의 개수
		cin >> start >> g >> h; // 개코로 g와 h 교차로 사이에 있는 도로를 지나갔다는 것을 알아냄 ㄷㄷ

		for (int i = 0; i <= n; i++) {
			adjacent[i].clear();
		}

		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			adjacent[u].push_back({ v, w });
			adjacent[v].push_back({ u, w });
		}

		vector<int> candidate;
		for (int i = 0; i < t; i++) {
			int temp;
			cin >> temp;
			candidate.push_back(temp);
		}

		sort(candidate.begin(), candidate.end());
		
		set<int> ans;

		for (auto i : candidate) {
			dijkstra(start);
			int toEnd = dist[i];
			int toG = dist[g];
			int toH = dist[h];
			dijkstra(g);
			int gtoH = dist[h];
			int gtoEnd = dist[i];
			dijkstra(h);
			int htoG = dist[g];
			int htoEnd = dist[i];



			if ((toG != INF && gtoH != INF && htoEnd != INF) || (toH != INF && htoG != INF && gtoEnd != INF)) {
				if (toEnd == toG + gtoH + htoEnd || toEnd == toH + htoG + gtoEnd) ans.insert(i);
			}
		}
		
		//cout << "ans : ";
		for (auto i : ans) {
			cout << i << " ";
		}
		cout << endl;
	}

	return 0;
}