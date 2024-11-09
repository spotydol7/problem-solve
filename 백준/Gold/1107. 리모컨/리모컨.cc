#include <iostream>
#include <string>
using namespace std;

int broken[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

int remote(int n) {
	int ans_plus = 500000000, ans_minus = -100;
	int temp = n;
	while (1) {
		int sum = 0;
		string n_str = to_string(n);
		for (int i = 0; i < n_str.length(); i++) {
			char ch = n_str[i];
			sum += broken[n_str[i] - '0'];
		}
		if (sum == 0) {
			ans_minus = n;
			break;
		}
		else {
			if (n == 0) break;
			else n--;
		}
	}
	n = temp;
	while (1) {
		int sum = 0;
		string n_str = to_string(n);
		for (int i = 0; i < n_str.length(); i++) {
			char ch = n_str[i];
			sum += broken[n_str[i] - '0'];
		}
		if (sum == 0) {
			ans_plus = n;
			break;
		}
		else {
			n++;
			if (n - temp > temp - ans_minus) {
				break;
			}
		}
	}
	if (ans_plus - temp >= temp - ans_minus) return ans_minus;
	else return ans_plus;
}

int main()
{
	int n, m, temp;
	
	cin >> n;
	string n_str = to_string(n);
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> temp;
		broken[temp] = 1;
	}
	if (n == 100) cout << "0" << '\n';
	else if (m == 0) {
		if (abs(n - 100) > n_str.length())
			cout << n_str.length() << '\n';
		else cout << abs(n - 100) << '\n';
	}
	else if (m == 10) {
		cout << abs(n - 100) << '\n';
	}
	else {
		int ans = remote(n);
		if (abs(n - ans) + to_string(ans).length() < abs(100 - n)) {
			cout << abs(n - ans) + to_string(ans).length() << '\n';
		}
		else {
			cout << abs(100 - n) << '\n';
		}
	}

	return 0;
}