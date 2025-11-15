#include <bits/stdc++.h>
using namespace std;

bool visited[10001];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;

        memset(visited, false, sizeof(visited));

        queue<pair<int, string>> q;
        q.push({a, ""});
        visited[a] = true;

        while(!q.empty()) {
            int cur = q.front().first;
            string curStr = q.front().second;
            if (cur == b) {
                cout << curStr << '\n';
                break;
            }

            q.pop();

            for (int i = 0; i < 4; i++) {
                int next, mod, quotient;
                char c;
                switch(i) {
                    case 0:
                        next = cur * 2;
                        if (next > 9999) next = next % 10000;
                        c = 'D';
                        break;

                    case 1:
                        next = cur - 1;
                        if (cur == 0) next = 9999;
                        c = 'S';
                        break;
                    
                    case 2:
                        mod = cur % 1000;
                        quotient = cur / 1000;
                        next = mod * 10 + quotient;
                        c = 'L';
                        break;
                    
                    case 3:
                        mod = cur % 10;
                        quotient = cur / 10;
                        next = mod * 1000 + quotient;
                        c = 'R';
                        break;
                }

                if (visited[next]) continue;
                string nextStr = curStr + c;
                q.push({next, nextStr});
                visited[next] = true;
            }
        }
    }
    return 0;
}