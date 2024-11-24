#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int visited[10];

void answer(int num) {
	if (num == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			arr[num] = i;
			visited[i] = 1;
			answer(num + 1);
			visited[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	answer(0);

	return 0;
}