#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	
	stack<pair<int, int>> towers;
	towers.push({ 100000001, 0 });

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;

		while (towers.top().first < temp) {
			towers.pop();
		}
		cout << towers.top().second << ' ';

		towers.push({ temp, i + 1 });
	}
	
	return 0;
}