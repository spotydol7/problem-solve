#include <bits/stdc++.h>
using namespace std;

int bin_search(int start, int end, int target, vector<int> arr) {
    int mid;
    while (start < end) {
        mid = (start + end) / 2;

        if (arr[mid] < target) 
            start = mid + 1;
        else
            end = mid;
    }

    return end;
}

int main() {
    int T, N, K;
    cin >> T;

    for (int test_case = 0; test_case < T; test_case++) {
        cin >> N >> K;

        vector<int> price;
        vector<int> lis;
        
        for (int i = 0; i < N; i++) {
            int temp;
            cin >> temp;
            price.push_back(temp);
        }

        lis.push_back(price[0]);

        for (int i = 0; i < N; i++) {
            if (price[i] > lis.back()) {
                lis.push_back(price[i]);
            } 
            else {
                int index = bin_search(0, lis.size() - 1, price[i], lis);
                lis[index] = price[i];
            }
        }
        int ans = 0;
        if (lis.size() >= K) ans = 1;

        cout << "Case #" << test_case + 1 << '\n' << ans << '\n';
    }

    return 0;
}