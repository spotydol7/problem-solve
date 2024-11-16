#include<iostream>

using namespace std;

int arr[101][101];
int code[60];
int interpret[10][7] = {
    {0, 0, 0, 1, 1, 0, 1},
    {0, 0, 1, 1, 0, 0, 1},
    {0, 0, 1, 0, 0, 1, 1},
    {0, 1, 1, 1, 1, 0, 1},
    {0, 1, 0, 0, 0, 1, 1},
    {0, 1, 1, 0, 0, 0, 1},
    {0, 1, 0, 1, 1, 1, 1},
    {0, 1, 1, 1, 0, 1, 1},
    {0, 1, 1, 0, 1, 1, 1},
    {0, 0, 0, 1, 0, 1, 1}
};
int num[8];

int main(int argc, char** argv)
{
	int test_case;
	int T, n, m;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
				scanf("%1d", &arr[i][j]);
            }
        }
        
        bool found = false;
        for (int i = 0; i < n; i++) {
        	for (int j = m - 1; j >= 0; j--) {
            	if (arr[i][j] == 1) {
                    found = true;
                	for (int k = 0; k < 56; k++) {
                    	code[55 - k] = arr[i][j - k];
                    }
                    break;
                }
            }
            if (found) break;
        }
        
        
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 10; j++) {
                bool same = true;
                for (int k = 0; k < 7; k++) {
                    if (code[(i * 7) + k] != interpret[j][k]) {
                        same = false;
                    	break;
                    }
                }
                if (same) {
                	num[i] = j;
                    break;
                }
            }
        }
        
        int sum = (num[0] + num[2] + num[4] + num[6]) * 3 + num[1] + num[3] + num[5] + num[7];
        int ans = num[0] + num[1] + num[2] + num[3] + num[4] + num[5] + num[6] + num[7];
        
        if (sum % 10 == 0) cout << '#' << test_case << ' '<< ans << endl;
        else cout << '#' << test_case << ' '<< 0 << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}