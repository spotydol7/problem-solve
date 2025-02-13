#include <bits/stdc++.h>
using namespace std;

int longestCommonSubSequence[1002][1002];

int main() {
    string str1, str2;
    cin >> str1;
    cin >> str2;

    int ans = 0;
    for (int i = 1; i <= str1.length(); i++) {
        for (int j = 1; j <= str2.length(); j++) {
            if (str1[i - 1] == str2[j - 1]) {
                longestCommonSubSequence[i][j] = longestCommonSubSequence[i - 1][j - 1] + 1;
            }
            else {
                longestCommonSubSequence[i][j] = max(longestCommonSubSequence[i - 1][j], longestCommonSubSequence[i][j - 1]);
            }
            ans = max(longestCommonSubSequence[i][j], ans);
        }
    }

    cout << ans;

    return 0;
}