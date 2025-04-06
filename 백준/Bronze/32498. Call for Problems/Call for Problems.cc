#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int cnt = 0;
    cin >> n;

    while (n--) {
        int r;
        cin >> r;

        if (r % 2 == 1) cnt++;
    }

    cout << cnt << '\n';

    return 0;
}