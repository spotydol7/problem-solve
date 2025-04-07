#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int ccw(pair<long long, long long> p1, pair<long long, long long> p2, pair<long long, long long> p3) {
	long long s = p1.X * p2.Y + p2.X * p3.Y + p3.X * p1.Y;
	s -= (p2.X * p1.Y + p3.X * p2.Y + p1.X * p3.Y); // 사선공식

	if (s > 0) return 1;
	else if (s == 0) return 0;
	else return -1;
} 

bool isIntersect(pair<pair<long long, long long>, pair<long long, long long>> l1, pair<pair<long long, long long>, pair<long long, long long>> l2) {
	pair<long long, long long> p1 = l1.first;
	pair<long long, long long> p2 = l1.second;
	pair<long long, long long> p3 = l2.first;
	pair<long long, long long> p4 = l2.second;

	int p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4); // l1 기준
	int p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2); // l2 기준

	// 두 직선이 일직선 상에 존재
	if (p1p2 == 0 && p3p4 == 0) {
		// 비교 제대로 하기 위해 swap
		if (p1 > p2) swap(p2, p1);
		if (p3 > p4) swap(p3, p4);

		return p3 <= p2 && p1 <= p4; // 두 선분이 포개어져 있는지 확인
	}

	return p1p2 <= 0 && p3p4 <= 0;
}

int main() {
	int x1, y1, x2, y2;
	int x3, y3, x4, y4;

	cin >> x1 >> y1 >> x2 >> y2;
	cin >> x3 >> y3 >> x4 >> y4;

	cout << isIntersect({ {x1, y1}, {x2, y2} }, { {x3, y3}, {x4, y4} });

	return 0;
}