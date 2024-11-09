#include <iostream>
using namespace std;

int DP(int n) {
    if (n <= 0) return 0;
    else if (n == 1) return 1;
    else if (n == 2) return 2;
    else if (n == 3) return 4;
    else {
        return DP(n - 1) + DP(n - 2) + DP(n - 3);
    }
}

int main() {
    int T, n;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n;
        cout << DP(n) << endl;
    }
    return 0;
}