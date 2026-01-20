#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int, vector<int>> pq_max;          
    priority_queue<int, vector<int>, greater<int>> pq_min;
    
    map<int, int> count_map;
    int num_count = 0;
    
    for(const auto& s : operations) {
        char oper = s[0];
        int num = stoi(s.substr(2));
        
        if(num_count == 0) {
            while(!pq_max.empty()) pq_max.pop();
            while(!pq_min.empty()) pq_min.pop();
            count_map.clear();
        }
        
        if(oper == 'I') {
             pq_max.push(num);
             pq_min.push(num);
             count_map[num]++;
             num_count++;
        }
        else {
            if(num_count == 0) continue;
            
            if(num == 1) {
                while(!pq_max.empty() && count_map[pq_max.top()] == 0) {
                    pq_max.pop();
                }
                if(!pq_max.empty()) {
                    int target = pq_max.top();
                    pq_max.pop();
                    count_map[target]--;
                    num_count--;
                }
            }
            else {
                while(!pq_min.empty() && count_map[pq_min.top()] == 0) {
                    pq_min.pop();
                }
                if(!pq_min.empty()) {
                    int target = pq_min.top();
                    pq_min.pop();
                    count_map[target]--;
                    num_count--;
                }
            }
        }
    }
    
    while(!pq_max.empty() && count_map[pq_max.top()] == 0) pq_max.pop();
    while(!pq_min.empty() && count_map[pq_min.top()] == 0) pq_min.pop();

    if(num_count > 0) {
        answer.push_back(pq_max.top());
        answer.push_back(pq_min.top());
    }
    else {
        answer.push_back(0);
        answer.push_back(0);
    }
    
    return answer;
}