#include <bits/stdc++.h>
using namespace std;

int N;
long long dp[1500052];
vector<int> times;
vector<int> prices;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int t, p;
        cin >> t >> p;
        times.push_back(t);
        prices.push_back(p);
    }

    for (int i = 0; i < N; i++) {
        // 오늘 상담안하고 내일로 넘김
        dp[i + 1] = max(dp[i + 1], dp[i]);

        // 오늘 상담을 함, 끝나는 날이 N 이하
        if (i + times[i] <= N) {
            dp[i + times[i]] = max(dp[i + times[i]], dp[i] + prices[i]);
        }
    }

    cout << dp[N];

    return 0;
}