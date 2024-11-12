#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

char arr[101][101];

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
    int n;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;
        vector<string> v;
        for (int i = 0; i < 100; i++) {
        	for (int j = 0; j < 100; j++) {
            	cin >> arr[i][j];
            }
        }
        
        string temp = "";
        vector<string> ansv;
        
        for (int i = 0; i < 100; i++) {
            temp = "";
        	for (int j = 0; j < 100; j++) {
            	if (arr[j][i] != '0') temp += arr[j][i];
            }
            if (temp.length() > 1) v.push_back(temp);
        }
        
        int ans = 0;

        for (int i = 0; i < v.size(); i++) {
        	string str = v[i];
            while(str.back() == '1') {
            	str.pop_back();
            }
            reverse(str.begin(), str.end());
            while(str.back() == '2') {
            	str.pop_back();
            }
            int cnt = 0;
            for (int i = 1; i < str.length(); i++) {
                if (str[i] == '1' && str[i - 1] == '2') cnt++;
            }
            ans += cnt;
        }
        
        cout << '#' << test_case << ' ' << ans << endl;
	}
	return 0;
}