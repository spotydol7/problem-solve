#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		long long a, b;
        long long c;
        long long ans;
        cin >> a >> b;
        c = b - a;
        if (c < 0) ans = -1;
        else if (c == 0) ans = 0;
        else if (c % 2 == 0) ans = c / 2;
        else if (c >= 3) ans = (c - 3) / 2 + 1;
        else ans = -1;
        
        cout << "#" << test_case << ' ' << ans << endl;
	}
	return 0;
}