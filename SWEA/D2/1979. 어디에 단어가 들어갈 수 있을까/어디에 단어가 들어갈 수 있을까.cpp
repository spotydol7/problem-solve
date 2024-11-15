#include<iostream>

using namespace std;

int arr[16][16];

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
        	for (int j = 0; j < n; j++) {
            	cin >> arr[i][j];
            }
        }
        
        int cnt = 0;
        // 가로
        for (int i = 0; i < n; i++) {
            int sum = 0;
        	for (int j = 0; j < n; j++) {
            	if (arr[i][j] == 1) sum++;
                if (arr[i][j] == 0) {
                	if (sum == k) cnt++;
                    sum = 0;
                }
            }
            if (sum == k) cnt++;
        }
        
        // 세로
        for (int i = 0; i < n; i++) {
        	int sum = 0;
            for (int j = 0; j < n; j++) {
            	if (arr[j][i] == 1) sum++;
                if (arr[j][i] == 0) {
                	if (sum == k) cnt++;
                    sum = 0;
                }
            }
             if (sum == k) cnt++;
        }
        
        cout << '#' << test_case << ' '<< cnt << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}