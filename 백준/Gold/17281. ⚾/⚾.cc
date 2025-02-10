#include <bits/stdc++.h>
using namespace std;

int n;
int arr[51][10]; // 이닝별 결과
int order[10]; // 타순
int base[4]; // 루( 1, 2, 3, 홈 ), 홈에 점수 누적
int ans = 0;

int calcScore() {
    int score = 0;
	int outCnt = 0;
	int lastHit = 0;
	bool threeOut = false;
	for (int i = 0; i < n; i++) {
        memset(base, 0, sizeof(base));
		threeOut = false;
        outCnt = 0;
		for (int j = lastHit; !threeOut; j++) {
			if (j == 9) j = 0;
			int hit = arr[i][order[j] - 1];
			if (hit == 0) {
				outCnt++;
				if (outCnt == 3) {
					lastHit = j + 1;
					threeOut = true;
				}
			}
			else if (hit == 1) { // 안타
				base[3] += base[2];
				base[2] = 0;
				base[2] += base[1];
				base[1] = 0;
				base[1] += base[0];
				base[0] = 1;
                
			}
			else if (hit == 2) { // 2루타
				base[3] += base[2];
				base[3] += base[1];

				base[2] = 0;
				base[2] += base[0];
				base[1] = 1;
				base[0] = 0;
			}
			else if (hit == 3) { // 3루타
				base[3] += base[2];
				base[3] += base[1];
				base[3] += base[0];

				base[2] = 0;
				base[2] = 1;
				base[1] = 0;
				base[0] = 0;
			}
			else if (hit == 4) { // 홈런
				int run = 0;
				for (int k = 0; k < 3; k++) {
					run += base[k];
					base[k] = 0;
				}
				base[3] += run;
				base[3]++;
			}
		}
        score += base[3];
	}
	return score;
}

void ordering(int bat) {
	if (bat == 9) {
		int score = calcScore();
		ans = score > ans ? score : ans;
	}
	else if (bat == 0) {
		order[3] = bat + 1;
		ordering(bat + 1);
	}
	else {
		for (int i = 0; i < 9; i++) {
			if (order[i] == 0) {
				order[i] = bat + 1;
				ordering(bat + 1);
				order[i] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
		}
	}

	ordering(0);
    cout << ans;
	return 0;
}