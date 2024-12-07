#include <bits/stdc++.h>
using namespace std;

int arr[130][130];
int white = 0, blue = 0;

void paper(int x, int y, int k) {
	bool divide = false;
	for (int i = y; i < y + k; i++) {
		for (int j = x; j < x + k; j++) {
			if (arr[i][j] != arr[y][x]) {
				divide = true;
				break;
			}
		}
	}
	if (divide) {
		paper(x, y, k / 2);
		paper(x, y + k / 2, k / 2);
		paper(x + k / 2, y, k / 2);
		paper(x + k / 2, y + k / 2, k / 2);
	}
	else {
		if (arr[y][x]) blue++;
		else white++;
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	paper(0, 0, n);
	cout << white << '\n' << blue << '\n';


	return 0;
}