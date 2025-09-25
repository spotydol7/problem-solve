#include <string>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

bool visited[51];

bool isConvertable(string a, string b) {
    int cnt = 0;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) cnt++;
        if (cnt > 1) return false;
    }
    if (cnt == 1) return true;
    else return false;
}

int solution(string begin, string target, vector<string> words) {
    
    queue<pair<int, string>> q;
    q.push({0, begin});
    
    while (!q.empty()) {
        int curDepth = q.front().first;
        string cur = q.front().second;
        q.pop();
        
        for (int i = 0; i < words.size(); i++) {
            if (!visited[i] && isConvertable(cur, words[i])) {
                if (words[i] == target) return curDepth + 1;
                visited[i] = true;
                q.push({curDepth + 1, words[i]});
            }
        }
    }
    
    return 0;
}