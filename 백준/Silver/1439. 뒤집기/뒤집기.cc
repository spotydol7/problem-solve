#include <bits/stdc++.h>
using namespace std;

int main() {
	string str;
	cin >> str;

	int ans = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != str[i + 1]) ans++;
	}
	if (!ans) cout << ans;
	else cout << ans / 2;

	return 0;
}