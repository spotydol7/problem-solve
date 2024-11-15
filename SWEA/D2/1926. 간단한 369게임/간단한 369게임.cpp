#include<iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
    	string str = to_string(i);
        int cnt = 0;
        for (int j = 0; j < str.length(); j++) {
        	if (str[j] == '3' || str[j] == '6' || str[j] == '9') {
            	cnt++;
            }
        }
        if (cnt == 0) cout << str << ' ';
        else {
            for (int j = 0; j < cnt; j++) cout << '-';
        	cout << ' ';
        }
    }
	return 0;
}