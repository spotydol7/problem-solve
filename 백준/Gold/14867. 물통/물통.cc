#include <bits/stdc++.h>
using namespace std;

int a, b, c, d; // a의 용량 / b의 용량 / a에 남길 물 / b에 남길 물
map<pair<int, int>, bool> visited;

int bfs() {
	queue<tuple<int, int, int>> q; // a, b 현재 물, depth
	
	q.push({ 0, 0, 0 });

	while (!q.empty()) {
		int curA = get<0>(q.front());
		int curB = get<1>(q.front()); // 커비 ㅋㅋ
		int curDepth = get<2>(q.front());

		//cout << "curA : " << curA << " curB " << curB << " curDepth " << curDepth << '\n';
		visited[{curA, curB}] = true;

		if (curA == c && curB == d) return curDepth;

		q.pop();

		for (int i = 0; i < 6; i++) {
			int nextA, nextB;

			if (i == 0) {
				nextA = a;
				nextB = curB;
				if (visited[{nextA, nextB}]) continue;

				q.push({ nextA, nextB, curDepth + 1 });
				visited[{nextA, nextB}] = true;

				if (nextA == c && nextB == d) return curDepth;
			}
			else if (i == 1) {
				nextA = 0;
				nextB = curB;
				if (visited[{nextA, nextB}]) continue;

				q.push({ nextA, nextB, curDepth + 1 });
				visited[{nextA, nextB}] = true;

				q.push({ nextA, nextB, curDepth + 1 });

				if (nextA == c && nextB == d) return curDepth;
			}
			else if (i == 2) { // Mab
				if (b - curB >= curA) {
					nextA = 0;
					nextB = curB + curA;
					if (visited[{nextA, nextB}]) continue;

					q.push({ nextA, nextB, curDepth + 1 });
					visited[{nextA, nextB}] = true;

					q.push({ nextA, nextB, curDepth + 1 });

					if (nextA == c && nextB == d) return curDepth;
				}
				else {
					nextA = curA - (b - curB);
					nextB = b;
					if (visited[{nextA, nextB}]) continue;

					q.push({ nextA, nextB, curDepth + 1 });
					visited[{nextA, nextB}] = true;

					q.push({ nextA, nextB, curDepth + 1 });

					if (nextA == c && nextB == d) return curDepth;
				}
			}
			else if (i == 3) {
				nextB = b;
				nextA = curA;
				if (visited[{nextA, nextB}]) continue;

				q.push({ nextA, nextB, curDepth + 1 });
				visited[{nextA, nextB}] = true;

				q.push({ nextA, nextB, curDepth + 1 });

				if (nextA == c && nextB == d) return curDepth;
			}
			else if (i == 4) {
				nextB = 0;
				nextA = curA;
				if (visited[{nextA, nextB}]) continue;

				q.push({ nextA, nextB, curDepth + 1 });
				visited[{nextA, nextB}] = true;

				q.push({ nextA, nextB, curDepth + 1 });

				if (nextA == c && nextB == d) return curDepth;
			}
			else if (i == 5) { // Mba
				if (a - curA >= curB) {
					nextA = curA + curB;
					nextB = 0;
					if (visited[{nextA, nextB}]) continue;

					q.push({ nextA, nextB, curDepth + 1 });
					visited[{nextA, nextB}] = true;

					q.push({ nextA, nextB, curDepth + 1 });

					if (nextA == c && nextB == d) return curDepth;
				}
				else {
					nextB = curB - (a - curA);
					nextA = a;
					if (visited[{nextA, nextB}]) continue;

					q.push({ nextA, nextB, curDepth + 1 });
					visited[{nextA, nextB}] = true;

					q.push({ nextA, nextB, curDepth + 1 });

					if (nextA == c && nextB == d) return curDepth;
				}
			}
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b >> c >> d;
	/*
	가능한 작업
	1. 물통 x에 물 가득 채우기
	2. 물통 x의 물 다 버리기
	3. 물통 x의 물을 물통 y에 붓기, 남으면 x에 남김
	*/
	int ans = bfs();
	if (ans != -1) ans += 1;
	if (c == 0 && d == 0) {
		ans = 0;
	}
	cout << ans;

	return 0;
}