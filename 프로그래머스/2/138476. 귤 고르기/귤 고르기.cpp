#include <algorithm>
#include <vector>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    sort(tangerine.begin(), tangerine.end());
    
    vector<int> v(tangerine.back(), 0);
    
    for (int i = 0; i < tangerine.size(); i++) {
        v[tangerine[i] - 1]++;
    }
    
    sort(v.rbegin(), v.rend());
    
    for (int i = 0; i < v.size(); i++) {
        answer++;
        k -= v[i];
        if (k <= 0) break;
    }
    
    return answer;
}