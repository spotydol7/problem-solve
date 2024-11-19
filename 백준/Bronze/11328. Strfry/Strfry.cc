#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while(n--) {
        int abc[27] = {};
        string str1;
        string str2;
        bool ans = true;
        cin >> str1 >> str2;

        for (auto c : str1) {
            abc[c - 'a']++;
        }
        for (auto c : str2) {
            abc[c - 'a']--;
        }

        for (int i : abc) {
            if (i != 0) ans = false;
        }

        if (ans) cout << "Possible" << '\n';
        else cout << "Impossible" << '\n';
    }

    return 0;
}