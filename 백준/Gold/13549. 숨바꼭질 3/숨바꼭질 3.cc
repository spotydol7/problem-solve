#include <bits/stdc++.h>
using namespace std;

int d[100001];

int main() {
    int n, k;
    cin >> n >> k;
    if (n == k) {
        cout << 0;
        return 0;
    }

    fill(d, d + 100001, -1);
    d[n] = 0;
    queue<int> q;
    q.push(n);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int next : {2 * cur, cur - 1, cur + 1}) {
            if (next < 0 || next > 100000) continue;
            if (d[next] != -1) continue;
            if (next == 2 * cur) d[next] = d[cur];
            else d[next] = d[cur] + 1;
            q.push(next);
        }
    }


    cout << d[k];

    return 0;
}