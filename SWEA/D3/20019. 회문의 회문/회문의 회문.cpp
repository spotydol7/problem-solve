#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool isPalindrome(string s) {
	string r = s;
    reverse(s.begin(), s.end());
    if (s == r) return true;
    else return false;
}

int main(int argc, char** argv) {
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		string s;
        cin >> s;
        int half = (s.length() - 1) / 2;
        string first = s;
        string second = s;
        first.erase(half, half + 1);
        second.erase(0, half + 1);
        
        //cout << endl << "first: " << first << " second: " << second << endl;
        
        if (isPalindrome(s) && isPalindrome(first) && isPalindrome(second)) {
        	cout << '#' << test_case << " YES" << endl;
        } else cout << '#' << test_case << " NO" << endl;
	}
	return 0;
}