#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int st = 0, en = 0;
    int cnt = 1;
    int ans = 0;
    cin >> n;

    vector<int> thr(n);
    vector<int> freq(10, 0);

    for (int i = 0; i < n; i++) {
        cin >> thr[i];
    }

    freq[thr[st]]++;

    while(st <= en && en < n) {
        if (cnt <= 2) {
            ans = max(ans, en - st + 1);
            en++;
            if (!freq[thr[en]]) cnt++;
            freq[thr[en]]++;
        }
        else {
            freq[thr[st]]--;
            if (!freq[thr[st]]) cnt--;
            st++;
        }
    }

    cout << ans;

    return 0;
}