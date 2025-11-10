#include<bits/stdc++.h>
using namespace std;

int T;

int main() {
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        string p, arr;
        cin >> p;
        cin >> n;
        cin >> arr;
        deque<int> dq;
        int num = 0;
        bool reading = false;
        for (int i = 1; i < (int)arr.length() - 1; i++) { 
            if (isdigit(arr[i])) {
                reading = true;
                num = num * 10 + (arr[i] - '0');
            } else {
                if (reading) {
                    dq.push_back(num);
                    num = 0;
                    reading = false;
                }
            }
        }
        if (reading) dq.push_back(num);

        bool rev = false;
        bool ok = true;

        for (char c : p) {
            if (c == 'R') {
                rev = !rev;
            } else { // D
                if (dq.empty()) {
                    ok = false;
                    break;
                }
                if (!rev) dq.pop_front();
                else dq.pop_back();
            }
        }

        if (!ok) {
            cout << "error\n";
            continue;
        }

        cout << "[";
        if (!dq.empty()) {
            if (!rev) {
                for (int i = 0; i < dq.size(); i++) {
                    if (i) cout << ",";
                    cout << dq[i];
                }
            } else {
                for (int i = dq.size() - 1; i >= 0; i--) {
                    if (i != dq.size() - 1) cout << ",";
                    cout << dq[i];
                }
            }
        }
        cout << "]\n";
        
    }

    return 0;
}