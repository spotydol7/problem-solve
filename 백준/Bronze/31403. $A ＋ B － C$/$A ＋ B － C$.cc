#include<bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c;
	cin >> a;
	cin >> b;
	cin >> c;
	int ans1 = a + b - c;
	string astr = to_string(a);
	string bstr = to_string(b);
	string str = astr + bstr;
	
	int num = 0;
	for (int i = 0; i < str.size(); i++) {
		num += str[i] - '0';
		num *= 10;
	}
	num /= 10;

	int ans2 = num - c;

	cout << ans1 << '\n' << ans2;
	return 0;
}