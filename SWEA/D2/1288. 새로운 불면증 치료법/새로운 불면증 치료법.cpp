#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    int flag = (1 << 10) - 1;
    for (int test_case = 1; test_case <= T; test_case++) {
        int n;
        cin >> n;
        int cnt = 1;
        int ans = 0;

        while (true) {
            int temp = n * cnt;
            while (temp != 0) {
                int a = temp % 10;
                temp /= 10;
                ans = ans | (1 << a);
            }

            if (ans == flag) {
                cout << "#" << test_case << " " << cnt * n << '\n';
                break;
            }
            cnt++;
        }
    }

    return 0;
}