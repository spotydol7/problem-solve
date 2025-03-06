#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0);
	
	int T;
	cin >> T;

	// M의 이진수 표현의 마지막 N 비트가 모두 1로 켜져 있는지
	for (int tc = 1; tc <= T; tc++) {
		int n, m;
		cin >> n >> m;

		int flag = (1 << n) - 1;
		int num = (m | flag);

		if (m == num && m != 0) 
			cout << "#" << tc << " ON\n";
		else 
			cout << "#" << tc << " OFF\n";
	}

	return 0;
}

/*
5
4 0
4 30
4 47
5 31
5 62


#1 OFF
#2 OFF
#3 ON
#4 ON
#5 OFF
*/