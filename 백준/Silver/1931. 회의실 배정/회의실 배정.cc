#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    else return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<pair<int, int>> v;

    int n, start, end;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> start >> end;
        v.push_back({start, end});
    }
    sort(v.begin(), v.end(), compare);

    int t = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (t <= v[i].first) {
            cnt++;
            t = v[i].second;
        }
    }

    cout << cnt << '\n';

    return 0;
}