#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int T, n, m, temp;
	deque<pair<int,int>> printer;
	cin >> T;
	for (int i = 0; i < T; i++) {
		printer.clear();
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			printer.push_back(make_pair(i, temp));
		}

		int max = 0, cnt = 0;
		while (1) {
			for (int i = 0; i < printer.size(); i++) {
				if (printer.at(i).second > max) 
					max = printer.at(i).second;
			}

			if (printer.front().second < max) {
				printer.push_back(printer.front());
				printer.pop_front();
			}

			else if (printer.front().second == max) {
				if (printer.front().first != m) {
					printer.pop_front();
					cnt++;
					max = 0;
					for (int i = 0; i < printer.size(); i++) {
						if (printer.at(i).second > max) 
							max = printer.at(i).second;
					}
				}

				else {
					printer.pop_front();
					cnt++;
					cout << cnt << '\n';
					break;
				}
			}
		}
	}

	return 0;
}