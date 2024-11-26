#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (temp == 0) {
            if (!q.empty()) {
                cout << q.top() << '\n';
                q.pop();
            }
            else cout << 0 << '\n';
        }
        else {
            q.push(temp);
        }
    }

    return 0;
}