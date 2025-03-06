#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

// Bit DP ㅋㅋ 빡셈

int n;
int w[16][16];
int memo[16][1 << 16];

int dp(int x, int visited) {
	if (visited == (1 << n) - 1) { // 방문 다 함 ㅇㅇ
		return w[x][0] != 0 ? w[x][0] : INF; // 처음 도시(0)으로 가는 비용
	}

	if (memo[x][visited] != -1) return memo[x][visited];
	
	memo[x][visited] = INF;
	
	for (int i = 0; i < n; i++) {
		if (w[x][i] != 0 && !(visited & (1 << i))) { // 만약 갈 수 있는 도시이고(W 값이 0이 아니면) 아직 방문하지 않은 도시라면(visited에 i가 속해있지 않다면)
			// visited & (1 << i)는 i번째 비트가 1인지 확인하는 연산으로 앞에 !를 붙여 비트가 0인지 확인
			memo[x][visited] = min(memo[x][visited], dp(i, visited | (1 << i)) + w[x][i]); 
			// dp(i, visited | (1 << i)) + w[x][i] -> visited의 i번째 비트를 1로 바꾸어 주고 재귀 들어감
		}
	}
	
	return memo[x][visited];
}

int main() {	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> w[i][j];
		}
	}

	memset(memo, -1, sizeof(memo));
	int ans = dp(0, 1);
	cout << ans;

	return 0;
}