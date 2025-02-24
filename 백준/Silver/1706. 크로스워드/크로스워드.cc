#include <bits/stdc++.h>
using namespace std;

int main() {
	int r, c;
	cin >> r >> c;
	vector<string> v;
	for (int i = 0; i < r; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}

	string str = "";

	vector<string> ans;

	// 가로
	for (int i = 0; i < r; i++) {
		str = "";
		for (int j = 0; j < c; j++) {
			if (v[i][j] != '#') {
				str.push_back(v[i][j]);
			}
			else {
				if (str != ""  && str.length() >= 2)
					ans.push_back(str);
				str = "";
			}
		}
		if (str != "" && str.length() >= 2) ans.push_back(str);
	}

	for (int i = 0; i < c; i++) {
		str = "";
		for (int j = 0; j < r; j++) {
			if (v[j][i] != '#') {
				str.push_back(v[j][i]);
			}
			else {
				if (str != "" && str.length() >= 2)
					ans.push_back(str);
				str = "";
			}
		}
		if (str != "" && str.length() >= 2) ans.push_back(str);
	}

	sort(ans.begin(), ans.end());

	cout << ans[0];
	/*
	4 5
	adaca
	da##b
	abb#b
	abbac
	*/
	return 0;
}