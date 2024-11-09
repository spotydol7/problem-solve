#include <iostream>
#include <cmath>
#define distance (sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)))
using namespace std;


int main()
{
	int t;
	double x1, y1, r1, x2, y2, r2;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		if ((x1 == x2) && (y1 == y2) && (r1 == r2)) {
			cout << -1 << '\n';
		}
		else if (distance > r1 + r2 || distance < abs(r2-r1)) {
			cout << 0 << '\n';
		}
		else if (distance == r1 + r2 || distance == abs(r2-r1)){
			cout << 1 << '\n';
		}
		else
			cout << 2 << '\n';
	}

	return 0;
}