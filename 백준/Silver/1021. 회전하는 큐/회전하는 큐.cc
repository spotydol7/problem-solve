#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    int cnt = 0;
    deque<int> dq;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        dq.push_back(i);
    }

    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        int idx = find(dq.begin(), dq.end(), temp) - dq.begin(); // find함수는 iterator 반환해서 begin() 빼줘야함
        while (dq.front() != temp) {
            if (idx < dq.size() - idx) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            else {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            cnt++;
        }
        dq.pop_front();
    }

    cout << cnt;
    return 0;
}