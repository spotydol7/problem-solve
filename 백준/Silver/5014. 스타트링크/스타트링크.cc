#include<bits/stdc++.h>
using namespace std;

int f, s, g, u, d;
int arr[1000001];
int visited[1000001];

int main() {
    cin >> f >> s >> g >> u >> d;
    int updown[2] = {u, (-1) * d};
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < 2; i++) {
            int next = cur + updown[i];
            if (next < 1 || next > f) continue;
            if (visited[next] > 0) continue;
            q.push(next);
            visited[next] = visited[cur] + 1;
        }
    }

    if (s == g) {
        cout << 0;
    } else if (visited[g] == 0) {
        cout << "use the stairs";
    } else {
        cout << visited[g] - 1;
    }
    return 0;
}