#include <bits/stdc++.h>
using namespace std;

int visited[1000001];

int getHammingDistance(int a, int b) {
    int xorResult = a ^ b;
    int result = 0;

    while (xorResult > 0)
    {
        result += xorResult & 1;
        xorResult = xorResult >> 1;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M; 
    cin >> N >> M;

    int lim = 2;
    while(lim <= N) // N보다 큰 2의 제곱수 중에 제일 작은 수 찾기
        lim = (lim << 1);

    queue<int> q;
    for(int i = 0; i < M; i++) {
        int temp; 
        cin >> temp;
        visited[temp] = 1;
        q.push(temp); // 시작점이 여러 개인 bfs
    }

    int ans = 0;
    while(!q.empty()) {
        ans++;
        int size = q.size(); // 그 level에서 갈 수 있는 노드 수?
        for(int i = 0; i < size; i++) {
            int x = q.front(); 
            q.pop();
            for(int j = 1; j < lim; (j <<= 1)) {
                int next = x ^ j; // XOR 연산
                if(next > N) continue;
                if(visited[next]) continue;
                visited[next] = true;
                q.push(next);
            }
        }
    }
    cout << ans - 1;
}