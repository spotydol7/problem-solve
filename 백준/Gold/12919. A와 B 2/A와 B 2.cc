#include <bits/stdc++.h>
using namespace std;

string s, t;
bool isPossible = false;

void dfs(string str) {
    if (str == s) {
        isPossible = true;
        return;
    }
    
    if (str.length() <= s.length()) return;

    if (str.back() == 'A') {
        string temp = str;
        temp.pop_back();
        dfs(temp);
    }
    
    if (isPossible) return;

    if (str.front() == 'B') {
        string temp = str;
        reverse(temp.begin(), temp.end());
        temp.pop_back();
        dfs(temp);
    }
}

int main() {
    cin >> s >> t;
    dfs(t);

    cout << (isPossible ? 1 : 0) << '\n';
    return 0;
}