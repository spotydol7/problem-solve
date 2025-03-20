#include <bits/stdc++.h>
using namespace std;

int n, k;

int binarySearch() {
    int start = 1;
    int end = k;
    while (start < end) {
        int mid = (start + end) / 2;
        int cnt = 0;

        for (int i = 1; i <= n; i++) 
            cnt += min(n, (mid / i));
        
        if (cnt < k) start = mid + 1;
        else end = mid;
    }

    return end;
}

int main() {
    cin >> n >> k;

    cout << binarySearch();

    return 0;
}