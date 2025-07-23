#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, S;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    cin >> S;

    for (int i = 0; i < N && S > 0; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < N && j - i <= S; j++) {
            if (v[j] > v[maxIdx]) {
                maxIdx = j;
            }
        }

        if (maxIdx != i) {
            for (int j = maxIdx; j > i; j--) {
                swap(v[j], v[j - 1]);
            }
            S -= (maxIdx - i);
        }
    }

    for (int i = 0; i < N; i++) {
        cout << v[i] << ' ';
    }
    cout << '\n';
    return 0;
}
