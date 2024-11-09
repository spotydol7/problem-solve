#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    stack<pair<int, int>> s;
    cin >> n;
    s.push(make_pair(100000001, 0)); // height, index
    for (int i = 1; i <= n; i++) {
        int height;
        cin >> height;
        while (s.top().first < height) {
            s.pop();
        }
        cout << s.top().second << ' ';
        s.push(make_pair(height, i));
    }
    return 0;
}