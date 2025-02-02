#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, b, c;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    cin >> b >> c;
    long long cnt = n;
    for (int i = 0; i < n; i++) {
        v[i] -= b;
		if (v[i] > 0) cnt += (v[i] + c - 1) / c;
    }
    cout << cnt;
    return 0;
}