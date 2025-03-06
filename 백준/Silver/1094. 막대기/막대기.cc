#include <bits/stdc++.h>
using namespace std;

int main() {
	int x;
	cin >> x;

	int ans = bitset<7>(x).count();

	cout << ans;

	return 0;
}