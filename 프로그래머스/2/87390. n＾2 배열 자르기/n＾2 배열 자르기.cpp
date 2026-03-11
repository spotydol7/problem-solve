#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for (long long i = left; i <= right; i++) {
        int div = i / n; 
        int mod = i % n;
        int num = 0;

        if(div >= mod) {
            num = div + 1;     
        }
        else {
            num = (div + 1) + (mod - div);     
        }

        answer.push_back(num);
    }
    
    return answer;
}