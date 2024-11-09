#include<iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case) {
        int n, temp, ans;
        int max = 0;
        vector<int> v(1001, 0);
        cin >> n;
        for (int i = 0; i < 1000; i++) {
        	cin >> temp;
            v[temp]++;
        }
        for (int i = 0; i < 1000; i++) {
        	if (v[i] >= max) {
                max = v[i];
            	ans = i;
            }
        }
        
        cout << "#" << test_case << ' ' << ans << endl; 
	}
	return 0;
}