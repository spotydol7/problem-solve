#include <bits/stdc++.h>
using namespace std;

int main() {
	string str;
	cin >> str;

	int k, d, a;
	int cnt = 0;

	int temp = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '/') {
			cnt++;
			temp /= 10;
			if (cnt == 1) {
				k = temp;
			}
			else if (cnt == 2) {
				d = temp;
			}
			temp = 0;
		}
		else {
			temp += str[i] - '0';
			temp *= 10;
		}
	}
	a = temp / 10;

	//cout << k << ' ' << d << ' ' << a << endl;

	if (k + a < d || d == 0) cout << "hasu";
	else cout << "gosu";
	return 0;
}