#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
    string str;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> str;
        int cnt = 0;
        
        if (str[0] == '1') cnt++;
        
        for (int i = 1; i < str.length(); i++) {
        	if (str[i] != str[i - 1]) cnt++;
        }
        
        cout << '#' << test_case << ' ' << cnt << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}