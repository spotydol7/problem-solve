#include <bits/stdc++.h>

using namespace std;

struct Segment_Tree {
    int N;
    vector<int> tree;
    bool is_min_tree;

    int merge_min(int left, int right) {
        return min(left, right);
    }

    int merge_max(int left, int right) {
        return max(left, right);
    }

    // 재귀적으로 세그먼트 트리를 구축하는 함수
    int buildRec(const vector<int>& arr, int node, int nodeLeft, int nodeRight) {
        if (nodeLeft == nodeRight) {
            return tree[node] = arr[nodeLeft];
        }
        int mid = nodeLeft + (nodeRight - nodeLeft) / 2;
        int leftVal = buildRec(arr, node * 2, nodeLeft, mid);
        int rightVal = buildRec(arr, node * 2 + 1, mid + 1, nodeRight);

        if (is_min_tree) {
            return tree[node] = merge_min(leftVal, rightVal);
        }
        else {
            return tree[node] = merge_max(leftVal, rightVal);
        }
    }

    // 세그먼트 트리를 초기화하고 구축하는 공개 함수
    // arr: 원본 배열
    // size: 배열의 크기
    // min_tree: true면 최솟값 트리, false면 최댓값 트리
    void build(const vector<int>& arr, int size, bool min_tree) {
        N = size;
        is_min_tree = min_tree;
        tree.resize(N * 4);
        buildRec(arr, 1, 0, N - 1);
    }

    // 재귀적으로 특정 구간의 값을 질의하는 함수
    int queryRec(int left, int right, int node, int nodeLeft, int nodeRight) {
        // 겹치지 않는 경우
        if (right < nodeLeft || nodeRight < left) {
            // 최솟값 쿼리일 때는 최대 정수값 반환, 최댓값 쿼리일 때는 최소 정수값 반환
            return is_min_tree ? INT_MAX : INT_MIN;
        }
        // 완전히 포함되는 경우
        if (left <= nodeLeft && nodeRight <= right) {
            return tree[node];
        }
        // 일부만 겹치는 경우
        int mid = nodeLeft + (nodeRight - nodeLeft) / 2;
        int leftVal = queryRec(left, right, node * 2, nodeLeft, mid);
        int rightVal = queryRec(left, right, node * 2 + 1, mid + 1, nodeRight);

        if (is_min_tree) {
            return merge_min(leftVal, rightVal);
        }
        else {
            return merge_max(leftVal, rightVal);
        }
    }

    // 특정 구간의 값을 질의하는 공개 함수
    int query(int left, int right) {
        return queryRec(left, right, 1, 0, N - 1);
    }

    // 재귀적으로 배열의 특정 원소를 업데이트하는 함수
    int updateRec(int index, int newValue, int node, int nodeLeft, int nodeRight) {
        if (index < nodeLeft || nodeRight < index) {
            return tree[node];
        }
        if (nodeLeft == nodeRight) {
            return tree[node] = newValue;
        }
        int mid = nodeLeft + (nodeRight - nodeLeft) / 2;
        int leftVal = updateRec(index, newValue, node * 2, nodeLeft, mid);
        int rightVal = updateRec(index, newValue, node * 2 + 1, mid + 1, nodeRight);

        if (is_min_tree) {
            return tree[node] = merge_min(leftVal, rightVal);
        }
        else {
            return tree[node] = merge_max(leftVal, rightVal);
        }
    }

    // 배열의 특정 원소를 업데이트하는 공개 함수
    int update(int index, int newValue) {
        return updateRec(index, newValue, 1, 0, N - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    Segment_Tree min_st;
    min_st.build(arr, N, true);

    Segment_Tree max_st;
    max_st.build(arr, N, false);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        cout << min_st.query(a - 1, b - 1) << " " << max_st.query(a - 1, b - 1) << '\n';
    }

    return 0;
}