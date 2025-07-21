#include <bits/stdc++.h>
#define MAX 2001
using namespace std;

bool visited[MAX][MAX];

int bfs(int S) {
    queue<tuple<int, int, int>> q;
    q.push({1, 0, 0});
    visited[1][0] = true;

    while (!q.empty()) {
        auto [cur, clip, t] = q.front();
        q.pop();

        if (cur == S) return t;

        if (!visited[cur][cur]) {
            visited[cur][cur] = true;
            q.push({cur, cur, t + 1});
        }

        if (clip > 0 && cur + clip < MAX && !visited[cur + clip][clip]) {
            visited[cur + clip][clip] = true;
            q.push({cur + clip, clip, t + 1});
        }

        if (cur > 0 && !visited[cur - 1][clip]) {
            visited[cur - 1][clip] = true;
            q.push({cur - 1, clip, t + 1});
        }
    }

    return -1;
}

int main() {
    int S;
    cin >> S;
    cout << bfs(S) << '\n';
    return 0;
}
