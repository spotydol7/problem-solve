#include <string>
#include <vector>

using namespace std;

int arr[101];
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    vector<int> remain;
    for (int i = 0; i < speeds.size(); i++) {
        int p = progresses[i];
        int s = speeds[i];
        if ((100 - p) % s == 0) 
            remain.push_back((100 - p) / s);
        else remain.push_back((100 - p) / s + 1);
    }
    
    int max = remain[0];
    for (int i = 0; i < remain.size(); i++) {
        if (max < remain[i]) {
            answer.push_back(remain[i]);
            max = remain[i];
        }
        else answer.push_back(max);
    }
    
    for (int i = 0; i < answer.size(); i++) {
        arr[answer[i]]++;
    }
    answer.clear();
    
    for (int i = 0; i < 101; i++) {
        if (arr[i] > 0) answer.push_back(arr[i]);
    }
    
    return answer;
}