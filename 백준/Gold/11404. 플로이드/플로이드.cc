#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int n, m;
int cities[101][101];

int main() {
	cin >> n >> m;
	
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i != j) cities[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		cities[a][b] = min(cities[a][b], c);
	}

	for (int m = 1; m <= n; m++) {
		for (int s = 1; s <= n; s++) {
			for (int e = 1; e <= n; e++) {
				if (cities[s][e] > cities[s][m] + cities[m][e]) {
					cities[s][e] = cities[s][m] + cities[m][e];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (cities[i][j] == INF) cities[i][j] = 0;
			cout << cities[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}