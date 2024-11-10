#include<iostream>

using namespace std;

int plane[50][50];

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int n;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int ans = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
        	for (int j = 0; j < n; j++) {
            	scanf("%1d", &plane[i][j]);
            }
        }
        int half = (n - 1) / 2;
        for (int i = 0; i <= half; i++) {
        	for (int j = half - i; j < half - i + 2 * i + 1; j++) {
            	ans += plane[i][j];
            }
        }
        
        for (int i = half + 1; i < n; i++) {
        	for (int j = i - half; j < i - half + 2 * (n - 1 - i) + 1; j++) {
            	ans += plane[i][j];
            }
        }
        cout << "#" << test_case << ' ' << ans << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}