#include <bits/stdc++.h>
using namespace std;

vector<int> adjacent[51];
vector<pair<int, int>> scores;

int main() {
    int n;
    cin >> n;
    
    int a, b;
    
    while(true) {
        cin >> a >> b;
        if (a == -1) break;
        adjacent[a].push_back(b);
        adjacent[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (adjacent[i].size() == 0) continue;
        
        bool visited[51] = {false, };
        queue<pair<int, int>> q;
        q.push({i, 0});
        visited[i] = true;
        int maxDepth = 0;
        
        while (!q.empty()) {
            int cur = q.front().first;
            int depth = q.front().second;
            q.pop();

            maxDepth = depth > maxDepth ? depth : maxDepth;

            for (int j = 0; j < adjacent[cur].size(); j++) {
                int next = adjacent[cur][j];
                if (!visited[next]) {
                    q.push({next, depth + 1});
                    visited[next] = true;
                }
                
            }
        }
        scores.push_back({maxDepth, i});
    }
    
    sort(scores.begin(), scores.end());

    int cnt = 0;
    int score = scores[0].first;

    vector<int> v;
    for (int i = 0; i < scores.size(); i++) {
        if (scores[i].first == score) {
            cnt++;
            v.push_back(scores[i].second);
        }
    }

    cout << score << " " << cnt << '\n';
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    return 0;
}