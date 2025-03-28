#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int V, E;
vector<pair<int, pair<int, int>>> v;
int parent[10001];
int ans;

int findParent(int x){
    if(parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b){
    a = findParent(a);
    b = findParent(b);
    parent[b] = a;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> V >> E;
    for(int i = 0; i < E; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({c, {a, b}});
    }
    sort(v.begin(), v.end());
    for(int i = 1; i <= V; i++)
        parent[i] = i;

    int cnt = 0;
    for(int i = 0; i < v.size(); i++){
        pair<int, pair<int, int>> curEdge = v[i];
        int cost = curEdge.first;
        int now = curEdge.second.first;
        int next = curEdge.second.second;

        if(findParent(now) == findParent(next)) continue; // 사이클 확인 -> union-find

        unionParent(now, next);
        ans += cost;

        if(++cnt == V - 1) break;
    }
    cout << ans << '\n';
    return 0;
}