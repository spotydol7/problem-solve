#include <string>
#include <vector>
#include <numeric> 

using namespace std;

int GCD(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int LCM(int a, int b) {
    
    return (a / GCD(a, b)) * b;
}

int solution(vector<int> arr) {
    int answer = arr[0];
    
    for (int i = 1; i < arr.size(); i++) {
        answer = LCM(answer, arr[i]);
    }
    
    return answer;
}