#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> nums;
int arr[10];
bool visited[10];

void dfs(int depth, int idx) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = idx; i < N; i++) {
		arr[depth] = nums[i];
		dfs(depth + 1, i);
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}
	sort(nums.begin(), nums.end());

	dfs(0, 0);
	
	return 0;
}