#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n;
vector<pair<long long, long long>> coordinate;

int main() {
	cin >> n;

	pair<long long, long long> start; // 시작 꼭짓점

	for (int i = 0; i < n; i++) {
		long long x, y;
		cin >> x >> y;
		coordinate.push_back({ x, y });
	}

	start = coordinate[0];

	double ans = 0.0;

	for (int i = 0; i < n - 1; i++) {
		// start, coordinate[i], coordinate[i + 1]로 사선공식 계산해서 삼각형 넓이 계산
		ans += 0.5 * ((start.X * coordinate[i].Y + coordinate[i].X * coordinate[i + 1].Y + coordinate[i + 1].X * start.Y) 
				- (coordinate[i].X * start.Y + coordinate[i + 1].X * coordinate[i].Y + start.X * coordinate[i + 1].Y));
	}

	ans = abs(ans);

	printf("%.1lf", ans);

	

	return 0;
}