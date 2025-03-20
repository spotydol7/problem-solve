#include <bits/stdc++.h>
using namespace std;

int n, m;
int ans;
vector<int> arr;
vector<vector<int>> space;

void coordinateCompress(vector<int> v, vector<int> v2) { // 좌표 압축
	vector<int> temp_v;
	for (int i = 0; i < m; i++) {
		int idx = lower_bound(v.begin(), v.end(), v2[i]) - v.begin(); // 끝까지 탐색하면서 이상의 숫자가 처음으로 나오는 위치의 인덱스 번호 반환
		temp_v.push_back(idx);
	}
	space.push_back(temp_v);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		vector<int> v;
		vector<int> v2; // 얘는 정렬안함 원본으로씀ㅇㅇ
		for (int j = 0; j < m; j++) {
			int temp;
			cin >> temp;
			v.push_back(temp);
			v2.push_back(temp);
		}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end()); 
		
		coordinateCompress(v, v2);
	}

	for (int i = 0; i < n; i++) {
		
		for (int j = i + 1; j < n; j++) {
			bool flag = true;
			for (int k = 0; k < m; k++) {
				if (space[i][k] != space[j][k]) flag = false;
			}
			if (flag) ans++;
		}
	}

	cout << ans;

	return 0;
}