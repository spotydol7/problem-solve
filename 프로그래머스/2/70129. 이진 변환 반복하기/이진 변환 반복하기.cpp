#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    int cnt = 0;
    int zeros = 0;
    
    string str = s;
    
    while(str != "1") {
        string temp = "";
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '0') zeros++;
            else temp += str[i];
        }
        
        int len = temp.length();
        
        str = "";
        while (len != 0) {
            if (len % 2 == 1) str += '1';
            else str += '0';
            len /= 2;
        }
        
        reverse(str.begin(), str.end());
        
        cnt++;
    }
    
    answer.push_back(cnt);
    answer.push_back(zeros);
    
    return answer;
}