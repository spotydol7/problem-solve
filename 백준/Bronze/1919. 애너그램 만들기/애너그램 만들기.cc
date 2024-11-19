#include<bits/stdc++.h>
using namespace std;

int abc[27];

int main() {
    string str1, str2;
    cin >> str1;
    cin >> str2;

    for (auto c : str1) {
        abc[c - 'a']++;
    }
    for (auto c : str2) {
        abc[c - 'a']--;
    }

    int ans = 0;
    for (int i : abc) {
        if (i != 0) {
            if (i < 0) ans += i * (-1);
            else ans += i;
        }
    }

    cout << ans << '\n';

    return 0;
}