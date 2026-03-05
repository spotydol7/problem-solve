#include <map>
#include <queue>

using namespace std;

int solution(int k, vector<int> tangerine) {
    map<int, int> mp;
    for (int i = 0; i < tangerine.size(); i++)
        mp[tangerine[i]]++;

    priority_queue<int> pq;
    
    for (auto i : mp)
        pq.push(i.second);

    int answer = 0;
    int cnt = 0;
    while (!pq.empty() && cnt < k) {
        cnt += pq.top();
        answer++;
        pq.pop();
    }
    return answer;
}