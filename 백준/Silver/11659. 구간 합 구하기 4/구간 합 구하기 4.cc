#include <bits/stdc++.h>
using namespace std;

int arr[100001];
long long sum[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, a, b;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		if (i == 0) sum[i] = arr[i];
		else sum[i] = sum[i - 1] + arr[i];
	}


	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout << sum[b] - sum[a - 1] << '\n';
	}
	return 0;
}