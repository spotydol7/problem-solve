#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
    int n, m;
    int plane[16][16];
	cin >> T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int max = 0;
        int sum = 0;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
        	for (int j = 0; j < n; j++) {
            	cin >> plane[i][j];
            }
        }
        
        for (int i = 0; i < n - m + 1; i++) {
        	for (int j = 0; j < n - m + 1; j++) {
                sum = 0;
            	for (int k = 0; k < m; k++) {
                	for (int l = 0; l < m; l++) {
                    	sum += plane[i + k][j + l];
                    }
                }
                if (sum > max) max = sum;
            }
        }
        cout << "#" << test_case << ' ' << max << endl;
	}
	return 0;
}