#include <bits/stdc++.h>
using namespace std;

int plug[101]; // 멀티탭에 꽂힌거

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> v; // 순서
	for (int i = 0; i < k; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	int ans = 0;

	for (int i = 0; i < k; i++) {
		bool flag = false;

		// 경우 1 - 쓸라는게 꽂힌 경우 -> 걍 넘어감
		for (int j = 0; j < n; j++) {
			if (plug[j] == v[i]) {
				flag = true;
				break;
			}
		}
		if (flag) continue;

		// 경우 2 - 쓸라는게 안꽂혀있는데 자리 있음 -> 꽂고 넘어감
		for (int j = 0; j < n; j++) {
			if (plug[j] == 0) {
				flag = true;
				plug[j] = v[i];
				break;
			}
		}
		if (flag) continue;

		// 경우 3 - 쓸라는게 안꽂혀있는데 자리도 없음 -> 이게걍 문제임 ㅇㅇ
		int idx = -1; // 뺄 자리 idx
		int last = -1; // 제일 늦게 나오는거
		for (int j = 0; j < n; j++) {
			int temp = 0;
			for (int h = i + 1; h < k; h++) {
				if (plug[j] == v[h]) {
					break;
				}
				temp++;
			}
			if (temp > last) {
				last = temp;
				idx = j;
			}
		}
		plug[idx] = v[i];
		ans++;
	}

	cout << ans;

	return 0;
}