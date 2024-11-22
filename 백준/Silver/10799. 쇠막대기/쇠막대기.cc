#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    int ans = 0;
    stack<char> st;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            st.push(str[i]);
        }
        else if (str[i - 1] == '(') {
            st.pop();
            ans += st.size();
        }
        else {
            st.pop();
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}