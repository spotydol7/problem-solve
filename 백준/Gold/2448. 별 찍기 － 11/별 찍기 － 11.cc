#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> v;
    v.push_back("  *  ");
    v.push_back(" * * ");
    v.push_back("*****");
    for (int i = 3; i < n; i *= 2) {
        for (int j = i; j < 2 * i; j++) {
            v.push_back(v[j - i] + " " + v[j - i]);
        }
        for (int j = i; j < 2 * i; j++) {
            v[j - i] = string(i, ' ') + v[j - i] + string(i, ' ');
        }
    }
    for (int i = 0; i < n; i++) {
        cout << v[i] << '\n';
    }

    return 0;
}