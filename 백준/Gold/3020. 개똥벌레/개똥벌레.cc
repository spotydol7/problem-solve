#include <bits/stdc++.h>
using namespace std;

vector<int> suc;
vector<int> jong;

int sucs[500002];
int jongs[500002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, h;
    cin >> n >> h;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (i % 2 == 0) suc.push_back(x);
        else jong.push_back(x);
    }

    sort(suc.begin(), suc.end());
    sort(jong.begin(), jong.end());

    for (int i = 1; i <= h; i++) {
        sucs[i] = suc.size() - (lower_bound(suc.begin(), suc.end(), i) - suc.begin());
        jongs[i] = jong.size() - (lower_bound(jong.begin(), jong.end(), h - i + 1) - jong.begin());
    }

    int min = 200001;
    int cnt = 0;
    for (int i = 1; i <= h; i++) {
        int sum = sucs[i] + jongs[i];
        if (sum < min) {
            min = sum;
            cnt = 1;
        } else if (sum == min) {
            cnt++;
        }
    }

    cout << min << " " << cnt;

    return 0;
}