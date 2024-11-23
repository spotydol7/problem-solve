#include <bits/stdc++.h>
using namespace std;

int main() {
	string str;
	int num = 0;
	for (int i = 0; i < 3; i++) {
		cin >> str;
		if (str[0] > '0' && str[0] <= '9') {
			num = 0;
			for (auto c : str) {
				num += c - '0';
				num *= 10;
			}
			num /= 10;
			num += 3 - i;
		}
	}
	if (num % 3 == 0 && num % 5 == 0) cout << "FizzBuzz";
	else if (num % 3 == 0) cout << "Fizz";
	else if (num % 5 == 0) cout << "Buzz";
	else cout << num;

	return 0;
}