#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    getline(cin, str);
    int a = str[0] - '0';
    int b = str[4] - '0';
    int c = str[8] - '0';

    if (c == a + b) cout << "YES";
    else cout << "NO";

    return 0;
}