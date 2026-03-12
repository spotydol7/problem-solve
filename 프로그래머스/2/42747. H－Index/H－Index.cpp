#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer;
    sort(citations.rbegin(), citations.rend());
    
    for (int i = 0; i < citations.size(); i++) {
        if (citations[i] > i) answer++;
        else break;
    }
    
    return answer;
}