#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < i; j++) {
			cout << " ";
		}

		for (int k = 1; k <= (n * 2 - (i * 2 + 1)); k++) {
			cout << "*";
		}

		cout << '\n';
	}

	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= n - i - 1; j++) {
			cout << " ";
		}

		for (int k = 1; k <= (i * 2 + 1); k++) {
			cout << "*";
		}
        
		cout << '\n';
	}

}