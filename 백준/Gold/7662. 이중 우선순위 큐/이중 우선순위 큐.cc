#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    priority_queue<long long, vector<long long>, greater<long long>> min_q;
    priority_queue<long long, vector<long long>, less<long long>> max_q;
    map<long long, long long> cnt;
    while(t--) {
        while (!min_q.empty()) {
            min_q.pop();
        }
        while (!max_q.empty()) {
            max_q.pop();
        }
        cnt.clear();
        int n;
        cin >> n;
        while(n--) {
            char c;
            long long num;
            cin >> c >> num;

            if (c == 'I') {
                min_q.push(num);
                max_q.push(num);
                cnt[num]++;
            }
            else if (c == 'D') {
                if (num == -1) {
                    if (!min_q.empty()) {
                        cnt[min_q.top()]--;
                        min_q.pop();

                        while (!min_q.empty() && cnt[min_q.top()] == 0) {
                            min_q.pop();
                        }
                        while (!max_q.empty() && cnt[max_q.top()] == 0) {
                            max_q.pop();
                        }
                    }
                }
                if (num == 1) {
                    if (!max_q.empty()) {
                        cnt[max_q.top()]--;
                        max_q.pop();

                        while (!min_q.empty() && cnt[min_q.top()] == 0) {
                            min_q.pop();
                        }
                        while (!max_q.empty() && cnt[max_q.top()] == 0) {
                            max_q.pop();
                        }
                    }
                }
            }
        }

        while (!min_q.empty() && cnt[min_q.top()] == 0) {
            min_q.pop();
        }
        while (!max_q.empty() && cnt[max_q.top()] == 0) {
            max_q.pop();
        }
        if (max_q.empty() || min_q.empty()) cout << "EMPTY" << '\n';
        else cout << max_q.top() << " " << min_q.top() << '\n';
    }
    return 0;
}