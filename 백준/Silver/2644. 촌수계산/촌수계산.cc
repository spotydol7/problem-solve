#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
vector<int> adjacent[102];
int visited[102];

void bfs(int num) {
    queue<int> q;
    // visited[num] = 1;
    q.push(num);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < adjacent[cur].size(); i++) {
            int next = adjacent[cur][i];
            if (!visited[next]) {
                visited[next] = visited[cur] + 1;
                q.push(next);
            }
        }
    }
}

int main() {
    cin >> n;
    cin >> a >> b;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int c, d;
        cin >> c >> d;
        adjacent[c].push_back(d);
        adjacent[d].push_back(c);
    }

    bfs(a);

    if (visited[b] == 0) visited[b]--;

    cout << visited[b];

    return 0;
}