#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    vector<int> v1;
    vector<int> v2;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v1.push_back(temp);
        v2.push_back(temp);
    }

    sort(v2.begin(), v2.end());
    v2.erase(unique(v2.begin(), v2.end()), v2.end());

    for (int i = 0; i < n; i++) {
        int idx = lower_bound(v2.begin(), v2.end(), v1[i]) - v2.begin(); 
        // lower_bound : 찾고자 하는 값보다 같거나 큰 숫자가 처음 등장하는 위치 iterator 반환 (없다면 last(v.end()) 반환), iter 간 차이 연산은 두 iter가 가리키는 위치의 상대적인 거리 반환
        cout << idx << ' '; 
    }

    return 0;
}