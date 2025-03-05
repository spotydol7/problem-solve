#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int N = -1;
int board[126][126];
int dist[126][126];
int dr[] = { 1, -1, 0, 0 };
int dc[] = { 0, 0, 1, -1 };

struct compare {
	bool operator() (pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
		if (a.second == b.second) return a.first > b.first;
		return a.second > b.second;
	}
};

void dijkstra(int r, int c) {
	priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, compare> pq;

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			dist[i][j] = INF;
		}
	}

	dist[r][c] = board[r][c];
	pq.push({ {r, c}, dist[r][c] });

	while (!pq.empty()) {
		int curR = pq.top().first.first;
		int curC = pq.top().first.second;
		int weightSum = pq.top().second;
		pq.pop();
		
		for (int i = 0; i < 4; i++) {
			int nr = curR + dr[i];
			int nc = curC + dc[i];

			if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;

			int nextWeight = board[nr][nc];
			if (dist[nr][nc] > nextWeight + weightSum) {
				dist[nr][nc] = nextWeight + weightSum;
				pq.push({ {nr, nc}, dist[nr][nc] });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int test_case = 1;
	while (1) {
		cin >> N;
		if (N == 0) break;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> board[i][j];
			}
		}

		dijkstra(0, 0);

		cout << "Problem " << test_case << ": " << dist[N - 1][N - 1] << '\n';
		test_case++;
	}

	return 0;
}