#include <bits/stdc++.h>
using namespace std;

struct cmp {
        bool operator()(int a, int b) {
        if (abs(a) == abs(b)) {
            return a > b;
        }
        return abs(a) > abs(b);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long x;
    priority_queue<int, vector<int>, cmp> pq;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x != 0) {
            pq.push(x);
        }
        else if (!pq.empty()) {
            cout << pq.top() << '\n';
            pq.pop();
        }
        else {
            cout << 0 << '\n';
        }
    }
    
    return 0;
}