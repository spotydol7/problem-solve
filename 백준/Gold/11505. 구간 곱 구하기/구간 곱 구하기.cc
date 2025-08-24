#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;

struct SegTree {
    int N;
    vector<ll> tree; 

    ll merge(ll a, ll b) { return (a * b) % MOD; }

    void build(const vector<ll>& arr) {
        N = 1;
        while (N < (int)arr.size()) N <<= 1;
        tree.assign(N << 1, 1); // 곱셈이라 1로 채움

        for (int i = 0; i < (int)arr.size(); i++) {
            tree[N + i] = arr[i] % MOD;
        }
            
        for (int i = N - 1; i >= 1; i--) {
            tree[i] = merge(tree[i<<1], tree[i << 1 | 1]);
        }
    }

    void update(int pos, ll val) {
        int idx = N + pos;
        tree[idx] = (val % MOD + MOD) % MOD;
        idx >>= 1;
        while (idx >= 1) {
            tree[idx] = merge(tree[idx<<1], tree[idx << 1 | 1]);
            idx >>= 1;
        }
    }

    ll query(int l, int r) {
        ll leftRes = 1, rightRes = 1;
        l += N; r += N;
        while (l <= r) {
            if (l & 1) 
                leftRes = merge(leftRes, tree[l++]);
            if (!(r & 1)) 
                rightRes = merge(tree[r--], rightRes);
            l >>= 1; r >>= 1;
        }
        return merge(leftRes, rightRes);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    vector<ll> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        arr[i] %= MOD;
    }

    SegTree st;
    st.build(arr);

    int totalOps = M + K;
    while (totalOps--) {
        int type;
        ll b, c;
        cin >> type;
        if (type == 1) {
            cin >> b >> c;
            st.update((int)b - 1, c);
        } else if (type == 2) {
            cin >> b >> c;
            cout << st.query((int)b - 1, (int)c - 1) << '\n';
        }
    }
    return 0;
}