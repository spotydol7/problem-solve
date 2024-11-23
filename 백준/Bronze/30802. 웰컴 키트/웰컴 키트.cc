#include<bits/stdc++.h>
using namespace std;

int tsize[6];

int main() {
	int n;
	int t, p;

	cin >> n;
	cin >> tsize[0] >> tsize[1] >> tsize[2] >> tsize[3] >> tsize[4] >> tsize[5];
	cin >> t >> p;

	int tshirt = 0;

	for (int i = 0; i < 6; i++) {
		if (tsize[i] == 0) tshirt += 0;
		else if (tsize[i] >= t) {
			if (tsize[i] % t == 0) {
				tshirt += tsize[i] / t;
			}
			else tshirt += tsize[i] / t + 1;
		}
		else {
			tshirt++;
		}
	}

	int pen = 0;
	int penset = 0;

	if (n < p) {
		penset = 0;
		pen = n;
	}
	else {
		penset = n / p;
		pen = n % p;
	}

	cout << tshirt << '\n' << penset << ' ' << pen;

	return 0;
}