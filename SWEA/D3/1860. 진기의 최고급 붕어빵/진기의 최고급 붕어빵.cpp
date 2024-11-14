#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int n, m, k;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        vector<int> customer;
        cin >> n >> m >> k;
        
        for (int i = 0; i < n; i++) {
        	int temp;
            cin >> temp;
            customer.push_back(temp);
        }
        sort(customer.begin(), customer.end());
        
        string ans = "Possible";
		for (int i = 0; i < n; i++) {
        	if (k * (customer[i] / m) < i + 1) {
                ans = "Impossible";
                break;
            }
        }
        cout << '#' << test_case << ' ' << ans << endl;
    }
	return 0;
}