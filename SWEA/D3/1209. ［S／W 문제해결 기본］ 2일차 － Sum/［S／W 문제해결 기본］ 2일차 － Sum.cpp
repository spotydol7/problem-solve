#include<iostream>

using namespace std;

int arr[101][101];

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int t, temp;
        cin >> t;
        
        for (int i = 0; i < 100; i++) {
        	for (int j = 0; j < 100; j++) {
            	cin >> arr[i][j];
            }
        }
        
        int max = 0;
        int sum = 0;
        for (int i = 0; i < 100; i++) {
        	sum = 0;
            for (int j = 0; j < 100; j++) {
            	sum += arr[i][j];
            }
            if (sum > max) max = sum;
        }
        
        sum = 0;
        for (int i = 0; i < 100; i++) {
        	sum = 0;
            for (int j = 0; j < 100; j++) {
            	sum += arr[j][i];
            }
            if (sum > max) max = sum;
        }
        
        sum = 0;
        for (int i = 0; i < 100; i++) {
        	sum += arr[i][i];
        }
        if (sum > max) max = sum;
        
        sum = 0;
        for (int i = 0; i < 100; i++) {
        	sum += arr[i][99 - i];
        }
        if (sum > max) max = sum;
        
        cout << '#' << test_case << ' ' << max << endl;
	}
	return 0;
}