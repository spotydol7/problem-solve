#include <bits/stdc++.h>
using namespace std;

int D(deque<int> &v, int reversed) {
	if (!v.empty() && !reversed) {
		v.pop_front();
		return 1;
	}
	else if (!v.empty() && reversed) {
		v.pop_back();
		return 1;
	}
	else if (v.empty()) {
		return -1;
	}
}

int main() {
	int t, n;
	string command, arr;
	cin >> t;
	for (int i = 0; i < t; i++) {
		deque<int> v;
		int temp = 0;
		int check = 0;
		int reversed = 0;
		cin >> command;
		cin >> n;
		cin >> arr;
		for (int i = 0; i < arr.length() - 1; i++) {
			if (arr[i] >= '0' && arr[i] <= '9') {
				temp += arr[i] - '0';
			}
			if (arr[i + 1] >= '0' && arr[i + 1] <= '9') {
				temp *= 10;
			}
			else if (n != 0) {
				v.push_back(temp);
				temp = 0;
			}
		}

		for (int i = 0; i < command.length(); i++) {
			if (command[i] == 'R') {
				//reverse(v.begin(), v.end());
				if (reversed) reversed = 0;
				else reversed = 1;
			}
			if (command[i] == 'D') {
				if (v.empty()) {
					check = -1;
					break;
				}
				if (n == 0) {
					check = -1;
					break;
				}
				check = D(v, reversed);
				if (check == -1) break;
			}

		}

		if (check == -1) {
			cout << "error" << '\n';
		}
		else if (!reversed) {
			cout << '[';
			for (int i = 0; i < v.size(); i++) {
				if (i == 0) {
					cout << v[i];
				}
				else {
					cout << ',' << v[i];
				}
			}
			cout << ']' << '\n';
		}
		else {
			cout << '[';
			for (int i = v.size() - 1; i >= 0; i--) {
				if (i == v.size() - 1) {
					cout << v[i];
				}
				else {
					cout << ',' << v[i];
				}
			}
			cout << ']' << '\n';
		}
	}

	return 0;
}