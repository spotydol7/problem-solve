#include <bits/stdc++.h>
using namespace std;

int num[10] = { 1,2,3,4,5,6,7,8,9 };
char op[3] = { ' ', '+', '-' };
char seq[10];

int cnt = 0;
int N;

bool isZero() {
    int sum = 0;
    int curr = num[0];
    char cmd = '+';
    for (int i = 0; i < N - 1; i++) {
        if (seq[i] == ' ') {
            curr = curr * 10 + num[i + 1];
        }
        else {
            if (cmd == '+') sum += curr;
            else              sum -= curr;
            cmd = seq[i];
            curr = num[i + 1];
        }
    }
    if (cmd == '+') sum += curr;
    else sum -= curr;
    return sum == 0;
}

void backtracking(int depth) {
    if (depth == N - 1) {
        if (isZero()) {
            for (int i = 0; i < N - 1; i++) {
                cout << num[i] << seq[i];
            }
            cout << num[N - 1] << '\n';
        }
        return;
    }
    for (int i = 0; i < 3; i++) {
        seq[depth] = op[i];
        backtracking(depth + 1);
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        backtracking(0);
        cout << '\n';
    }
    return 0;
}
