#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int cnt = 0;

	cin >> n;

	int temp = 1;
	while (temp < n) {
		temp += 6 * cnt;
		cnt++;
	}

	if (n != 1) cout << cnt;
	else cout << 1;
}