#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int N, M;
int board[101][101];
int dist[101][101];
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
		for (int j = 0; j <= M; j++) {
			dist[i][j] = INF;
		}
	}

	dist[r][c] = 0;
	pq.push({ {r, c}, 0 });

	while (!pq.empty()) {
		int curR = pq.top().first.first;
		int curC = pq.top().first.second;
		int weightSum = pq.top().second;
		pq.pop();

		if (dist[curR][curC] < weightSum) continue;

		for (int i = 0; i < 4; i++) {
			int nr = curR + dr[i];
			int nc = curC + dc[i];
			if (nr < 1 || nr > N || nc < 1 || nc > M) continue;
			int nextWeight = board[nr][nc];
			if (dist[nr][nc] > nextWeight + weightSum) {
				dist[nr][nc] = nextWeight + weightSum;
				pq.push({ {nr, nc}, dist[nr][nc] });
			}
		}
	}
}

int main() {
	cin >> M >> N;
	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= M; j++) {
			board[i][j] = str[j - 1] - '0';
		}
	}

	dijkstra(1, 1);
	cout << dist[N][M];

	return 0;
}