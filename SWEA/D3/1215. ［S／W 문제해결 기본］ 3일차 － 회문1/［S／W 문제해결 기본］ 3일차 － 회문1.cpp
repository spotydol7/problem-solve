#include<iostream>
#include <algorithm>

using namespace std;

char arr[9][9];

bool isPalindrome(string str) {
	string r_str = str;
    reverse(r_str.begin(), r_str.end());
    if (str == r_str) return true;
    return false;
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
    int n;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> n;
        for (int i = 0; i < 8; i++) {
        	for (int j = 0; j < 8; j++) {
            	cin >> arr[i][j];
            }
        }
        
        string temp = "";
        int ans = 0;
        
        // 가로
        for (int i = 0; i < 8; i++) {
        	for (int j = 0; j  <= 8 - n; j++) {
                temp = "";
            	for (int k = 0; k < n; k++) {
                	temp += arr[i][j + k];
                }
                if (isPalindrome(temp)) ans++;
            }
        }
        
        // 세로
        for (int i = 0; i <= 8 - n; i++) {
        	for (int j = 0; j < 8; j++) {
            	temp = "";
                for (int k = 0; k < n; k++) {
                	temp += arr[i + k][j];
                }
                if (isPalindrome(temp)) ans++;
            }
        }
        
        cout << '#' << test_case << ' ' << ans << endl;
	}
    
	return 0;
}