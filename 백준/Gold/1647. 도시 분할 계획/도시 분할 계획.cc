#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, pair<int, int>>> edges;
int parent[100001];
int totalCost = 0;

int findParent(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if(a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        edges.push_back({cost, {a, b}});
    }
    
    sort(edges.begin(), edges.end());
    
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    
    int cnt = 0;
    int maxCost = 0;
    
    for (auto edge : edges) {
        int cost = edge.first;
        int a = edge.second.first;
        int b = edge.second.second;
        
        if (findParent(a) != findParent(b)) {
            unionParent(a, b);
            totalCost += cost;
            maxCost = cost;
            cnt++;
            if (cnt == n - 1)
                break;
        }
    }
    
    cout << totalCost - maxCost << "\n";
    
    return 0;
}
