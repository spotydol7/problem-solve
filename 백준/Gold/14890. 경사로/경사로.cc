#include <bits/stdc++.h>
using namespace std;

int n, l;
int horizon[101][101];
int vertical[101][101];

int ans;

void cntRoad(int road[][101]) {
    for (int i = 0; i < n; i++) {
        int slope[101] = {0, };
        bool isPossible = true;
        for (int j = 0; j < n - 1; j++) {
            if (abs(road[i][j] - road[i][j + 1]) > 1) {
                isPossible = false;
                break;
            }

            if (road[i][j] == road[i][j + 1] + 1) {
                for (int k = j + 2; k < j + l + 1; k++) {
                    if (k >= n || road[i][k] != road[i][j + 1]) {
                        isPossible = false;
                        break;
                    }
                }
                if (isPossible) slope[j + l] = 1;
                else break;
            }

            if (road[i][j] == road[i][j + 1] - 1) {
                for (int k = j; k > j - l; k--) {
                    if (k < 0 || road[i][k] != road[i][j] || slope[k] == 1) {
                        isPossible = false;
                        break;
                    }
                }
                if (!isPossible) break;
            }
        }
        if (isPossible) ans++;
    }
}

int main() {
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> horizon[i][j];
            vertical[j][i] = horizon[i][j];
        }
    }

    cntRoad(horizon);
    cntRoad(vertical);

    cout << ans;

    return 0;
}