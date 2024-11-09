#include <bits/stdc++.h>
using namespace std;

int exist[10000001];
int num[10000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, temp, x, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        num[i] = temp;
        exist[temp]++;
    }
    cin >> x;

    for (int i = 0; i < n; i++) {
        if (exist[x - num[i]]) cnt++;
    }
    cnt /= 2;
    cout << cnt << '\n';

}