#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    string str;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        list<char> lt;
        list<char>::iterator iter = lt.begin();
        cin >> str;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '<') {
                if (iter != lt.begin()) iter--;
            }
            else if (str[i] == '>') {
                if (iter != lt.end()) iter++;
            }
            else if (str[i] == '-') {
                if (iter != lt.begin()) {
                    iter--;
                    iter = lt.erase(iter);
                }
            }
            else {
                lt.insert(iter, str[i]);
            }
        }
        for (auto i = lt.begin(); i != lt.end(); i++) {
            cout << *i;
        }
        cout << '\n';
    }
    return 0;
}