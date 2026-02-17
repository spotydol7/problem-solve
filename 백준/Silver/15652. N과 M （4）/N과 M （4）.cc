#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];

void dfs(int depth, int num) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = num; i <= N; i++) {
		arr[depth] = i;
		dfs(depth + 1, i);
	}
}

int main() {
	cin >> N >> M;

	dfs(0, 1);

	return 0;
}