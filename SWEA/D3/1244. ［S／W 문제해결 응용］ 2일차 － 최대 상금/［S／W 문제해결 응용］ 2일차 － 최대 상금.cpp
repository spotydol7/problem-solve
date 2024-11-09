#include <iostream>
#include <algorithm>

using namespace std;

int ans, cnt;
string s;

void dfs(int index, int current) {
    if(current == cnt) {
        ans = max(ans, stoi(s));
        return;
    }
    for(int i = index; i < s.size() - 1; i++) {
        for(int j = i + 1; j < s.size(); j++) {
            if (s[i] <= s[j]) {
                swap(s[i], s[j]);
                dfs(i, current + 1);
                swap(s[i], s[j]);
            }
            if (i == s.length() - 2 && j == s.length() - 1) {
            	swap(s[i], s[j]);
                dfs(i, current + 1);
                swap(s[i], s[j]);
            }
        }
    }
}

int main(void) {
    int t;
    cin >> t;
    
    for(int i = 1; i <= t; i++) {
        cin >> s >> cnt;
        ans = 0;

        dfs(0, 0);
        cout << "#" << i << " " << ans << endl;
    }
    return 0;
}