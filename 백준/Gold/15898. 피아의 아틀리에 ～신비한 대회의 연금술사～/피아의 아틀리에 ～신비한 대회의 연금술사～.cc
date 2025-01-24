#include <bits/stdc++.h>

using namespace std;

int n;
int ingres[10][4][4][4][2];
int used[10];
int picks[3];
int rotates[3];
int place[4][2] = { { 0, 0 }, { 0, 1 }, { 1, 0 }, { 1, 1 } };
int placed[3];
int sumArr[5];
int gama[5][5][2];
map<char, int> convert;

int makeBomb(int depth) {
	if (depth == 3) {
		for (int i = 0; i < 3; i++) {
			int y = place[placed[i]][0];
			int x = place[placed[i]][1];
			int pick = picks[i];
			int rotate = rotates[i];

			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					gama[j + y][k + x][0] = max(0, min(9, gama[j + y][k + x][0] + ingres[pick][rotate][j][k][0]));

					if (ingres[pick][rotate][j][k][1] > 0) {
						gama[j + y][k + x][1] = ingres[pick][rotate][j][k][1];
					}
				}
			}
		}

		for (int i = 0; i < 5; i++) sumArr[i] = 0;

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				sumArr[gama[i][j][1]] += gama[i][j][0];
				gama[i][j][0] = gama[i][j][1] = 0;
			}
		}

		return sumArr[1] * 7 + sumArr[2] * 5 + sumArr[3] * 3 + sumArr[4] * 2;
	}

	int ret = 0;

	for (int i = 0; i < 4; i++) {
		placed[depth] = i;
		ret = max(ret, makeBomb(depth + 1));
	}

	return ret;
}

int go(int depth) {
	if (depth == 3) return makeBomb(0);

	int ret = 0;

	for (int i = 0; i < 4; i++) {
		rotates[depth] = i;
		ret = max(ret, go(depth + 1));
	}

	return ret;
}

int solve(int depth) {
	if (depth == 3) return go(0);

	int ret = 0;

	for (int i = 0; i < n; i++) {
		if (used[i]) continue;

		picks[depth] = i;
		used[i] = 1;
		ret = max(ret, solve(depth + 1));
		used[i] = 0;
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	convert['W'] = 0;
	convert['R'] = 1;
	convert['B'] = 2;
	convert['G'] = 3;
	convert['Y'] = 4;

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < 4; k++) {
			for (int l = 0; l < 4; l++) {
				cin >> ingres[i][0][k][l][0];
			}
		}

		for (int k = 0; k < 4; k++) {
			for (int l = 0; l < 4; l++) {
				char c;

				cin >> c;

				ingres[i][0][k][l][1] = convert[c];
			}
		}

		for (int j = 1; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				for (int l = 0; l < 4; l++) {
					ingres[i][j][k][l][0] = ingres[i][j - 1][4 - l - 1][k][0];
					ingres[i][j][k][l][1] = ingres[i][j - 1][4 - l - 1][k][1];
				}
			}
		}
	}

	cout << solve(0);

	return 0;
}