#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    int start = 0;
    int end = n - 1;
    
    int ans = 2e9;
    int ans_start;
    int ans_end;

    while (start < end) {
        int a = v[start];
        int b = v[end];

        if (abs(a + b) < ans) {
            ans = abs(a + b);
            ans_start = a;
            ans_end = b;
        }

        if (a + b < 0) start++;
        else end--; 
    }
    cout << ans_start << " " << ans_end;

    return 0;
}