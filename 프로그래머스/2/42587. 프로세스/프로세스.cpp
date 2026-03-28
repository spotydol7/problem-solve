#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    queue<pair<int, int>> q;
    for (int i = 0; i < priorities.size(); i++) {
        q.push({priorities[i], i});
    }
    sort(priorities.rbegin(), priorities.rend());
    
    int idx = 0;
    int cnt = 0;
    while (true) {
        int p = q.front().first;
        int l = q.front().second;
        if (p == priorities[idx]) {
            cnt++;
            q.pop();
            idx++;
            if (l == location) {
                answer = cnt;
                break;
            }
        }
        else {
            q.pop();
            q.push({p, l});
        }
    }
    
    return answer;
}