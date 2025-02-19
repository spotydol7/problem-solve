#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;

	vector<long long> cards;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		cards.push_back(temp);
	}

	// m번의 합체를 모두 끝낸 뒤, n장의 카드에 쓰여있는 수를 모두 더한 값이 이 놀이의 점수가 된다. 이 점수를 가장 작게 만드는 것이 놀이의 목표이다.
	sort(cards.begin(), cards.end());
	for (int i = 0; i < m; i++) {
		cards[0] += cards[1];
		cards[1] = cards[0];
		sort(cards.begin(), cards.end());
	}

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += cards[i];
	}
	cout << ans << '\n';

	return 0;
}