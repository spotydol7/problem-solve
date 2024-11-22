#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	stack<char> st;
	cin >> str;
	int sum = 0;
	int by = 1;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			by *= 2;
			st.push(str[i]);
		}
		else if (str[i] == '[') {
			by *= 3;
			st.push(str[i]);
		}
		else if (str[i] == ')') {
			if (st.empty() || st.top() != '(') {
				cout << 0;
				return 0;
			}
			if (i > 0 && str[i - 1] == '(') sum += by;
			st.pop();
			by /= 2;
		}
		else if (str[i] == ']') {
			if (st.empty() || st.top() != '[') {
				cout << 0;
				return 0;
			}
			if (i > 0 && str[i - 1] == '[') sum += by;
			st.pop();
			by /= 3;
		}
	}

	if (!st.empty()) cout << 0 << '\n';
	else cout << sum << '\n';

	return 0;
}