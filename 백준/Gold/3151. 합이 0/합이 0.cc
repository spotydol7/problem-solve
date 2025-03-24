#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    long long cnt = 0;

    for (int i = 0; i < n; i++) {
        int start = i + 1;
        int end = n - 1;

        while (start < end) {
            int sum = v[i] + v[start] + v[end];
            if (sum == 0) {
                if (v[start] == v[end]) {
                    int count = end - start + 1;
                    cnt += count * (count - 1) / 2;
                    break;
                }

                int startCount = 1, endCount = 1;

                while (start + 1 < end && v[start] == v[start + 1]) {
                    start++;
                    startCount++;
                }

                while (end - 1 > start && v[end] == v[end - 1]) {
                    end--;
                    endCount++;
                }

                cnt += startCount * endCount;
                start++;
                end--;
            } else if (sum < 0) {
                start++;
            } else {
                end--;
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}