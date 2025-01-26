#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d, e, f;
    int x = 1111, y = 1111;
    cin >> a >> b >> c >> d >> e >> f;
    for (int i = -999; i <= 999; i++) {
        for (int j = -999; j <= 999; j++) {
            if (a * i + b * j == c && d * i + e * j == f) {
                x = i;
                y = j;
                break;
            }
        }
        if (x != 1111 && y != 1111) break;
    }
    cout << x << " " << y;
    return 0;
}