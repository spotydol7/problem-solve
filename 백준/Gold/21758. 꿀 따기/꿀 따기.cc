#include <bits/stdc++.h>
using namespace std;

int sum[100001];
int honey[100001];

int main() {
    int N, ans = -1;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> honey[i];
        sum[i] = sum[i - 1] + honey[i];
    }
    
    int total;
    // 벌꿀벌
    for (int i = 2; i < N; i++) {
        total = sum[i] - sum[1] + sum[N - 1] - sum[i - 1];
        ans = max(total, ans);
    }

    // 벌벌꿀
    for (int i = 2; i < N; i++) {
        total = sum[N] - sum[1] - honey[i] + sum[N] - sum[i];
        ans = max(total, ans);
    }

    // 꿀벌벌
    for (int i = 2; i < N; i++) {
        total = sum[N - 1] - honey[i] + sum[i - 1];
        ans = max(total, ans);
    }

    cout << ans << '\n';

    return 0;
}