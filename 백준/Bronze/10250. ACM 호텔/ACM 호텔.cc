#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int h, w, n;
		cin >> h >> w >> n;

		int floor;
		floor = n % h;
		int room = n / h + 1;

		if (floor == 0) {
			floor = h;
			room--;
		}

		string str = to_string(floor);
		string temp = to_string(room);
		if (temp.size() == 1) str.push_back('0');
		str += temp;

		cout << str << '\n';
	}
	return 0;
}