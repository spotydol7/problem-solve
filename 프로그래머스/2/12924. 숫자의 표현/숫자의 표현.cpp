#include <string>
#include <deque>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    deque<int> dq;
    
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
        dq.push_back(i);
        
        if (sum > n) {
            while (sum > n) {
                sum -= dq.front();
                dq.pop_front();
            }
        }
        
        if (sum == n) {
            answer++;
            sum -= dq.front();
            dq.pop_front();
        }
    }    
    
    return answer;
}