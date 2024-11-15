#include<iostream>

using namespace std;

int pascal[11][11];

int main(int argc, char** argv)
{
	int test_case;
	int T, n;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
    	cin >> n;
        
        pascal[0][0] = 1;
        pascal[1][0] = 1;
        pascal[1][1] = 1;
        for (int i = 2; i < n; i++) {
            pascal[i][0] = 1;
        	for (int j = 1; j <= i; j++) {
            	pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
            }
        }
        
        cout << '#' << test_case << endl;
        for (int i = 0; i < n; i++) {
        	for (int j = 0; j <= i; j++) {
            	cout << pascal[i][j] << ' ';
            }
            cout << endl;
        }
    }
	return 0;
}