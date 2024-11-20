#include<bits/stdc++.h>
using namespace std;

int pre[5001];
int nxt[5001];
vector<int> ans;
int n, k, len;

int main() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        pre[i] = i == 1 ? n : i - 1;
        nxt[i] = i == n ? 1 : i + 1;
        len++;
    }

    int i = 1;
    for (int cur = 1; len != 0; cur = nxt[cur]) {
        if (i == k) {
            pre[nxt[cur]] = pre[cur];
            nxt[pre[cur]] = nxt[cur];
            ans.push_back(cur);
            len--;
            i = 1;
        }
        else i++;
    }

    cout << '<';
    for (int i = 0; i < ans.size() - 1; i++) {
        cout << ans[i] << ", ";
    }
    cout << ans[ans.size() - 1] << '>' << '\n';
}