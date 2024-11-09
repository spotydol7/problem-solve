#include<iostream>
#include<vector>

using namespace std;

// [재료 수][칼로리]
int arr[21][10001] = {0, };

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int n, limit;
    
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int score, calory;
		vector<pair<int, int>> burger;
        cin >> n >> limit;
        for (int i = 0; i < n; i++) {
        	cin >> score >> calory;
            burger.push_back(make_pair(score, calory));
        }
        for (int i = 1; i <= n; i++) {
        	for (int j = 1; j <= limit; j++) {
            	int curcalory = burger[i - 1].second;
                int curscore = burger[i - 1].first;
                // 현재 보고 있는 재료를 넣을 수 있는 경우 max를 통해 아래 두 경우 중 더 큰 값 취함
                // 1. 재료를 넣지 않는다(바로 위 칸의 값 가져옴) arr[i - 1][j]
                // 2. 재료를 넣는다 arr[i - 1][j - curcalory] + curscore
                if (curcalory <= j) {
                	arr[i][j] = max(arr[i - 1][j - curcalory] + curscore, arr[i - 1][j]);
                }
                else arr[i][j] = arr[i - 1][j];
            }
        }
        
        cout << "#" << test_case << ' '<< arr[n][limit] << endl;
        
	}
	return 0;
}