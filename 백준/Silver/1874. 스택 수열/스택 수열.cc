#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int pushcnt[100001];
int popcnt[100001];

int main()
{
	int n, temp, num;
	vector<int> v;
	stack<int> s;
	bool cannot = false;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}

	for (num = 1; num <= v[0]; num++) {
		s.push(num);
		//cout << "+" << endl;
		pushcnt[0]++;
	}

	for (int i = 0; i < n; i++) {
		if (s.empty() || v[i] != s.top()) {
			if (s.empty() || v[i] > s.top()) {
				for (; num <= v[i]; num++) {
					//cout << "+" << endl;
					s.push(num);
					pushcnt[i]++;
				}
				//cout << "-" << endl;
				s.pop();
				popcnt[i]++;
				continue;
			}
			else if (v[i] < s.top()) {
				cout << "NO" << '\n';
				cannot = true;
				break;
			}
		}
		else if (v[i] == s.top()) {
			//cout << "-" << endl;
			s.pop();
			popcnt[i]++;
			continue;
		}
	}
	
	if (!cannot) {
		for (int i = 0; i < 100001; i++) {
			for (int j = 0; j < pushcnt[i]; j++) {
				cout << "+" << '\n';
			}
			for (int j = 0; j < popcnt[i]; j++) {
				cout << "-" << '\n';
			}
		}
	}
	

	return 0;
}