#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calendar(int m, int d) {
    int monthDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int sum = 0;
    for (int i = 1; i < m; i++) 
        sum += monthDays[i];
    return sum + d;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    vector<pair<int,int>> flowers;
    for(int i = 0; i < N; i++){
        int sm, sd, em, ed; // 시작은 inclusive, 끝은 exclusive
        cin >> sm >> sd >> em >> ed;
        int start = calendar(sm, sd);
        int end = calendar(em, ed);
        flowers.push_back({start, end});
    }
    
    // 시작 날짜 기준 정렬
    sort(flowers.begin(), flowers.end());
    
    int ans = 0;
    int current = calendar(3, 1); // 3월 1일부터
    int target = calendar(12, 1); // 11월 30일은 커버못치니까 12월 1일부터

    int idx = 0;
    int maxEnd = 0;
    
    while(current < target) {
        bool found = false;
        // 현재 구간 내에서 시작하는 꽃들
        while(idx < N && flowers[idx].first <= current) {
            maxEnd = max(maxEnd, flowers[idx].second);
            idx++;
            found = true;
        }
        // 가능한 꽃이 없으면 break
        if(!found) break;
        ans++; // 꽃 하나 선택
        current = maxEnd; // 구간 갱신
    }
    
    if(current < target) cout << 0;
    else cout << ans;
        
    return 0;
}
