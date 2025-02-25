#include <bits/stdc++.h>
using namespace std;

vector<int> adjacent[20001];
int visited[20001];
bool flag;

void bfs(int x) {
	queue<pair<int, int>> q; // bipartite graph : 인접한 노드는 다른 색으로 칠해서 2개 색만으로 다 채울 수 있을 때
	q.push({ x, 1 });
	visited[x] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		int color = q.front().second;
		q.pop();

		for (int i = 0; i < adjacent[cur].size(); i++) {
			int next = adjacent[cur][i];
			int nextColor = color * -1;

			if (visited[next] == 0) {
				q.push({ next, nextColor });
				visited[next] = nextColor;
			}
			else if (visited[next] == color) {
				flag = false;
				return;
			}
		}
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int v, e;
		cin >> v >> e;

		memset(visited, 0, sizeof(visited));
		for (int i = 0; i <= v; i++) {
			adjacent[i].clear();
		}

		for (int i = 0; i < e; i++) {
			int a, b;
			cin >> a >> b;
			adjacent[a].push_back(b);
			adjacent[b].push_back(a);
		}

		flag = true;
		for (int i = 1; i <= v; i++) {
			if (!flag) break;
			if (visited[i] == 0) bfs(i);
		}

		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}