#include<bits/stdc++.h>
using namespace std;

int maxDp[3], minDp[3];

int main() {
    int N;
    cin >> N;

    cin >> maxDp[0] >> maxDp[1] >> maxDp[2];
    minDp[0] = maxDp[0];
    minDp[1] = maxDp[1];
    minDp[2] = maxDp[2];

    for (int i = 1; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        int nextMax0 = max(maxDp[0], maxDp[1]) + a;
        int nextMax1 = max(max(maxDp[0], maxDp[1]), maxDp[2]) + b;
        int nextMax2 = max(maxDp[1], maxDp[2]) + c;

        maxDp[0] = nextMax0;
        maxDp[1] = nextMax1;
        maxDp[2] = nextMax2;

        int nextMin0 = min(minDp[0], minDp[1]) + a;
        int nextMin1 = min(min(minDp[0], minDp[1]), minDp[2]) + b;
        int nextMin2 = min(minDp[1], minDp[2]) + c;

        minDp[0] = nextMin0;
        minDp[1] = nextMin1;
        minDp[2] = nextMin2;
    }

    int maximum = max(max(maxDp[0], maxDp[1]), maxDp[2]);
    int minimum = min(min(minDp[0], minDp[1]), minDp[2]);

    cout << maximum << ' ' << minimum << '\n';

    return 0;
}