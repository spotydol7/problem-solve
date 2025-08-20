#include <bits/stdc++.h>
using namespace std;

struct Segment_Tree {
    int N;
    vector<long long> tree;
    vector<long long> lazy; // lazy 값을 저장할 배열

    // 두 자식 노드의 값을 합쳐 부모 노드의 값을 결정하는 함수
    long long merge(long long left, long long right) {
        return left + right; // 합계를 구함
    }

    // 재귀적으로 세그먼트 트리를 구축하는 함수
    void buildRec(const vector<long long>& arr, int node, int nodeLeft, int nodeRight) {
        if (nodeLeft == nodeRight) {
            tree[node] = arr[nodeLeft];
            return;
        }

        int mid = nodeLeft + (nodeRight - nodeLeft) / 2;
        buildRec(arr, node * 2, nodeLeft, mid);
        buildRec(arr, node * 2 + 1, mid + 1, nodeRight);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    // 초기 배열을 기반으로 세그먼트 트리를 구축
    void build(const vector<long long>& arr) {
        N = arr.size();
        tree.assign(N * 4, 0);
        lazy.assign(N * 4, 0);
        buildRec(arr, 1, 0, N - 1);
    }

    // Lazy 값을 자식 노드로 전파하는 함수
    void updateLazy(int node, int nodeLeft, int nodeRight) {
        if (lazy[node] != 0) {
            // 현재 노드에 lazy 값이 있으면 업데이트 적용
            tree[node] += lazy[node] * (nodeRight - nodeLeft + 1); // 자식 노드에 더해진 값 다 합쳐서 더해줌

            // 리프 노드가 아니면 자식 노드에 lazy 값 전파
            if (nodeLeft != nodeRight) {
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
            // 현재 노드의 lazy 값 초기화
            lazy[node] = 0;
        }
    }

    // 특정 구간의 값을 재귀적으로 업데이트하는 함수 (Lazy Propagation 사용)
    void updateRangeRec(int left, int right, long long diff, int node, int nodeLeft, int nodeRight) {
        // lazy 값 먼저 적용
        updateLazy(node, nodeLeft, nodeRight);

        // 현재 노드 구간이 업데이트 범위와 완전히 겹치지 않는 경우
        if (right < nodeLeft || nodeRight < left) {
            return;
        }

        // 현재 노드 구간이 업데이트 범위 안에 완전히 포함되는 경우
        if (left <= nodeLeft && nodeRight <= right) {
            // 현재 노드에 lazy 값 업데이트 (실제 트리 값은 나중에 업데이트)
            tree[node] += diff * (nodeRight - nodeLeft + 1);
            // 리프 노드가 아니면 자식에게 전파할 lazy 값 저장
            if (nodeLeft != nodeRight) {
                lazy[node * 2] += diff;
                lazy[node * 2 + 1] += diff;
            }
            return;
        }

        // 현재 노드 구간이 업데이트 범위와 부분적으로 겹치는 경우
        int mid = nodeLeft + (nodeRight - nodeLeft) / 2;
        updateRangeRec(left, right, diff, node * 2, nodeLeft, mid);
        updateRangeRec(left, right, diff, node * 2 + 1, mid + 1, nodeRight);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    // 특정 구간의 값 업데이트를 시작하는 함수
    void updateRange(int left, int right, long long diff) {
        updateRangeRec(left, right, diff, 1, 0, N - 1);
    }

    // 재귀적으로 특정 구간의 값을 질의(query)하는 함수
    long long queryRec(int left, int right, int node, int nodeLeft, int nodeRight) {
        // lazy 값 먼저 적용
        updateLazy(node, nodeLeft, nodeRight);

        // 현재 노드 구간이 질의 범위와 겹치지 않는 경우
        if (right < nodeLeft || nodeRight < left) {
            return 0; // 합계이므로 0 반환
        }

        // 현재 노드 구간이 질의 범위 안에 완전히 포함되는 경우
        if (left <= nodeLeft && nodeRight <= right) {
            return tree[node];
        }

        // 현재 노드 구간이 질의 범위와 부분적으로 겹치는 경우
        int mid = nodeLeft + (nodeRight - nodeLeft) / 2;
        long long leftVal = queryRec(left, right, node * 2, nodeLeft, mid);
        long long rightVal = queryRec(left, right, node * 2 + 1, mid + 1, nodeRight);
        return merge(leftVal, rightVal);
    }

    // 특정 구간의 값 질의를 시작하는 함수
    long long query(int left, int right) {
        return queryRec(left, right, 1, 0, N - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    vector<long long> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    Segment_Tree st;
    st.build(arr);

    int totalOps = M + K;
    while (totalOps--) {
        int type;
        cin >> type;

        if (type == 1) {
            int b, c;
            long long d;
            cin >> b >> c >> d;
            st.updateRange(b - 1, c - 1, d);
        }
        else {
            int b, c;
            cin >> b >> c;
            cout << st.query(b - 1, c - 1) << "\n";
        }
    }

    return 0;
}
