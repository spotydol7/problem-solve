#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int balance, amount;
        char op;
        cin >> balance >> op >> amount;
        if (balance == 0 && op == 'W' && amount == 0) 
            break;

        if (op == 'D') {
            balance += amount;
            cout << balance << '\n';
        }
        else {
            if (balance - amount < -200)
                cout << "Not allowed\n";
            else
                cout << (balance - amount) << '\n';
        }
    }
    return 0;
}
