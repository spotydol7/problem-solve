#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    int N;
    vector<long long> tree;

    long long merge(long long left, long long right) {
        return left + right;
    }

    long long buildRec(const long long arr[], int node, int nodeLeft, int nodeRight) {
        if (nodeLeft == nodeRight) 
            return tree[node] = arr[nodeLeft];

        int mid = nodeLeft + (nodeRight - nodeLeft) / 2;
        long long leftVal = buildRec(arr, node * 2, nodeLeft, mid);
        long long rightVal = buildRec(arr, node * 2 + 1, mid + 1, nodeRight);
        return tree[node] = merge(leftVal, rightVal);
    }

    void build(const long long arr[], int size) {
        N = size;
        tree.resize(N * 4);
        buildRec(arr, 1, 0, N - 1);
    }

    long long queryRec(int left, int right, int node, int nodeLeft, int nodeRight) {
        if (right < nodeLeft || nodeRight < left) 
            return 0;

        if (left <= nodeLeft && nodeRight <= right)
            return tree[node];

        int mid = nodeLeft + (nodeRight - nodeLeft) / 2;
        return merge(queryRec(left, right, node * 2, nodeLeft, mid), queryRec(left, right, node * 2 + 1, mid + 1, nodeRight));
    }

    long long query(int left, int right) {
        return queryRec(left, right, 1, 0, N - 1);
    }

    long long updateRec(int index, long long newValue, int node, int nodeLeft, int nodeRight) {
        if (index < nodeLeft || nodeRight < index) return tree[node];

        if (nodeLeft == nodeRight) return tree[node] = newValue;

        int mid = nodeLeft + (nodeRight - nodeLeft) / 2;
        long long leftVal = updateRec(index, newValue, node * 2, nodeLeft, mid);
        long long rightVal = updateRec(index, newValue, node * 2 + 1, mid + 1, nodeRight);

        return tree[node] = merge(leftVal, rightVal);
    }

    long long update(int index, long long newValue) {
        return updateRec(index, newValue, 1, 0, N - 1);
    }
};

long long arr[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    SegmentTree st;
    st.build(arr, n);

    for (int i = 0; i < m + k; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            int b;
            long long c;
            cin >> b >> c;
            st.update(b - 1, c);
        } else if (a == 2) {
            int b, c;
            cin >> b >> c;
            cout << st.query(b - 1, c - 1) << '\n';
        }
    }

    return 0;
}
