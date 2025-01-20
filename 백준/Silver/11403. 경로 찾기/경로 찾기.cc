#include <bits/stdc++.h>
#define INF 10000000
using namespace std;

int arr[101][101];
int n;

void floyd() {
	for (int m = 0; m < n; m++) {
		for (int s = 0; s < n; s++) {
			for (int e = 0; e < n; e++) {
				if (arr[s][e] > arr[s][m] + arr[m][e])
					arr[s][e] = arr[s][m] + arr[m][e];
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
				arr[i][j] = INF;
				arr[j][i] = INF;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp;
			cin >> temp;
			if (temp == 1) arr[i][j] = temp;
		}
	}

	floyd();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] < INF) cout << 1 << ' ';
			else cout << 0 << ' ';
		}
		cout << '\n';
	}
	   
	return 0;
}