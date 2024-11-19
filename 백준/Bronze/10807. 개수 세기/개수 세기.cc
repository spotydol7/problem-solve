#include <bits/stdc++.h>
using namespace std;

int num[101];
int mnum[101];

int main() {
    int n, v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (temp < 0) {
            temp *= -1;
            mnum[temp]++;
            temp *= -1;
        }
        else num[temp]++;
    }

    cin >> v;
    if (v < 0) cout << mnum[v * (-1)] << endl;
    else cout << num[v] << endl;

    return 0;
}