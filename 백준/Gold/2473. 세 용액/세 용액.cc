#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;
vector<int> ans;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	int ans_st = 0;
	int ans_i = 0;
	int ans_en = 0;
	long long min = LLONG_MAX;

	for (int i = 0; i < n; i++) {
		int st = 0;
		int en = n - 1;
		while (st < en) {
			if (st == i) {
				st++;
				continue;
			}
			if (en == i) {
				en--;
				continue;
			}
			long long sum = 0;
			sum += v[st];
			sum += v[i]; 
			sum += v[en];
			if (abs(sum) < min) {
				min = abs(sum);
				ans_st = st;
				ans_i = i;
				ans_en = en;
			}
			if (sum >= 0) en--;
			else st++;
		}
	}

	ans.push_back(v[ans_st]);
	ans.push_back(v[ans_i]);
	ans.push_back(v[ans_en]);

	sort(ans.begin(), ans.end());

	for (int a : ans) {
		cout << a << ' ';
	}

	return 0;
}