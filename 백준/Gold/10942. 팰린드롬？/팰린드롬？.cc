#include <bits/stdc++.h>
using namespace std;

int dp[2001][2001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n;

    vector<int> seq(n);
    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }

    // 길이가 1
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    // 길이가 2
    for (int i = 0; i < n - 1; i++) {
        if (seq[i] == seq[i + 1])
            dp[i][i + 1] = 1;
    }

    // 길이가 3 이상인 구간
    for (int i = n - 3; i >= 0; i--) {
        for (int j = i + 2; j < n; j++) {
            if (seq[i] == seq[j] && dp[i + 1][j - 1])
                dp[i][j] = 1;
        }
    }

    cin >> m;
    string output;
    output.reserve(m * 2); // 충분한 용량 미리 확보

    for (int t = 0; t < m; t++) {
        int s, e;
        cin >> s >> e;
        s--; e--; // 0-indexed로 변경
        output += (dp[s][e] ? "1\n" : "0\n");
    }
    cout << output;
    return 0;
}
