#include <bits/stdc++.h>
using namespace std;

int n, m;
int ans = INT_MAX;
int city[52][52];

vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;
int picked[52];

void calc() {
    int chickenDistance = 0;
    for (int i = 0; i < houses.size(); i++) {
        int houseMin = INT_MAX;
        for (int j = 0; j < chickens.size(); j++) {
            if (picked[j] == 1) {
                int d = abs(houses[i].first - chickens[j].first) + abs(houses[i].second - chickens[j].second);
                houseMin = min(d, houseMin);
            }
        }
        chickenDistance += houseMin;
    }
    ans = chickenDistance < ans ? chickenDistance : ans;
}

void pick(int idx, int level) {
	if (level == m) {
		calc();
	}
    else {
        for (int i = idx; i < chickens.size(); i++) {
            if (!picked[i]) {
                picked[i] = 1;
                pick(i + 1, level + 1);
                picked[i] = 0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> city[i][j];
			if (city[i][j] == 1)
				houses.push_back({ i, j });
			else if (city[i][j] == 2)
				chickens.push_back({ i, j });
		}
	}

    pick(0, 0);
    cout << ans << '\n';

	return 0;
}