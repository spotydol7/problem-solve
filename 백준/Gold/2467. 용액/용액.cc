#include <bits/stdc++.h>
#define INF 2e9
using namespace std;

int n;
vector<int> nums;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }

    int start = 0;
    int end = n - 1;
    int ans = INF;

    int ans_s;
    int ans_e;

    while (start < end) {
        int a = nums[start];
        int b = nums[end];

        if (abs(a + b) < ans) {
            ans = abs(a + b);
            ans_s = a;
            ans_e = b;
        }

        if(a + b < 0) start++;
        else end--;
    }

    cout << ans_s << " " << ans_e;

    return 0;
}