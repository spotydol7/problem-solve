#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    list<char> lt;
    int n;
    char command, instr;
    cin >> str;
    cin >> n;
    for (int i = 0; i < str.length(); i++) {
        lt.push_back(str[i]);
    }
    list<char>::iterator iter = lt.end();
    for (int i = 0; i < n; i++) {
        cin >> command;
        if (command == 'P') {
            cin >> instr;
            lt.insert(iter, instr);
        }
        else if (command == 'L') {
            if (iter != lt.begin()) iter--;
        }
        else if (command == 'D') {
            if (iter != lt.end()) iter++;
        }
        else if (command == 'B') {
            if (iter != lt.begin()) {
                iter--;
                iter = lt.erase(iter);
            }
        }
    }

    for (auto iter = lt.begin(); iter != lt.end(); iter++) {
        cout << *iter;
    }
}