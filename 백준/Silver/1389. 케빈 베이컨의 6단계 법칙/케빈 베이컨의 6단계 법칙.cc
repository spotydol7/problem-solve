#include <bits/stdc++.h>
#define INF 100000000;
using namespace std;

int n, m, a, b;
long long adjacent [101][101];
int d[101];

void floyd() {
    for (int m = 1; m <= n; m++) {
        for (int s = 1; s <= n; s++) {
            for (int e = 1; e <= n; e++) {
                if (adjacent[s][e] > adjacent[s][m] + adjacent[m][e])
                    adjacent[s][e] = adjacent[s][m] + adjacent[m][e];
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j)  {
                adjacent[i][j] = INF;
                adjacent[j][i] = INF;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adjacent[a][b] = 1;
        adjacent[b][a] = 1;
    }

    floyd();

    for (int i = 1; i <= n; i++) {
        long long sum = 0;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            sum += adjacent[i][j];
        }
        d[i] = sum;
    }
    int min = INF;
    int ans;
    for (int i = n; i >= 1; i--) {
        if(d[i] <= min) {
            min = d[i];
            ans = i;
        }
    }
    cout << ans << '\n';
    return 0;
}