#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    string cloth, category;
    cin >> T;
    while(T--) {
        int n;
        map<string, int> wear;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> cloth >> category;
            if (wear.find(category) == wear.end()) {
                wear.insert({category, 1});
            }
            else wear[category]++;
        }

        int ans = 1;
        for (auto i : wear) {
            ans *= (i.second + 1);
        }
        ans -= 1;
        cout << ans << '\n';
    }
    return 0;
}