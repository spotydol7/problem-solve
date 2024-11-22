#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        stack<char> st;
        cin >> str;
        for (auto c : str) {
            if (!st.empty() && st.top() == c) {
                st.pop();
            }
            else st.push(c);
        }
        if (st.empty()) ans++;
    }
    cout << ans << '\n';

    return 0;
}