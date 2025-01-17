#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    string temp = "";
    int ans = 0;
    bool minus = false;
    cin >> str;

    for (int i = 0; i <= str.size(); i++) {
        if (str[i] == '+' || str[i] == '-' || i == str.size()) {
            if (minus) ans -= stoi(temp);
            else ans += stoi(temp);
            temp = "";
        }
        else temp += str[i];
        if (str[i] == '-') minus = true;
    }

    cout << ans;
    return 0;
}