#include <bits/stdc++.h>
using namespace std;

int main() {
	string str;
	cin >> str;

	int ans = 10;
	for (int i = 1; i < str.length(); i++) {
		if (str[i] != str[i - 1]) ans += 10;
		else ans += 5;
	}

	cout << ans;
	return 0;
}