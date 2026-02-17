#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> nums;
int arr[10];
bool visited[10];

void dfs(int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
	}
	
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			arr[depth] = nums[i];
			visited[i] = true;
			dfs(depth + 1);
			visited[i] = false;
		}
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

	dfs(0);

	return 0;
}