#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	set<int> s;

	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		string command;
		cin >> command;
		if (command == "add") {
			int temp;
			cin >> temp;
			s.insert(temp);
		}
		else if (command == "remove") {
			int temp;
			cin >> temp;
			s.erase(temp);
		}
		else if (command == "check") {
			int temp;
			cin >> temp;
			if (s.count(temp)) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (command == "toggle") {
			int temp;
			cin >> temp;
			if (s.count(temp)) s.erase(temp);
			else s.insert(temp);
		}
		else if (command == "all") {
			s = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
		}
		else if (command == "empty") {
			s = {};
		}
	}

	return 0;
}