#include <iostream>
using namespace std;

int block[502][502];

int main()
{
	int n, m, b;
	cin >> n >> m >> b;

	int max = 0;
	int min = 257;

	int minTime = 100000000;
	int maxHeight = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> block[i][j];
		}
	}

	for (int i = 0; i <= 256; i++) {
		int putBlock = 0;
		int getBlock = 0;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				int heightD = block[j][k] - i;
				if (heightD < 0)
					putBlock -= heightD;
				else
					getBlock += heightD;
			}
		}
		if (getBlock + b >= putBlock) {
			int time = 2 * getBlock + putBlock;
			if (time <= minTime) {
				minTime = time;
				maxHeight = i;
			}
		}
	}

	cout << minTime << " " << maxHeight;

	return 0;
}