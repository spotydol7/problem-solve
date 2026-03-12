#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    map<string, int> mp;
    for (int i = 0; i < clothes.size(); i++) {
        mp[clothes[i][1]]++;
    }
    
    vector<int> v;
    for (auto i : mp) {
        v.push_back(i.second);
    }
    
    for (int i = 0; i < v.size(); i++) {
        answer *= (v[i] + 1);
    }
    
    return answer - 1;
}