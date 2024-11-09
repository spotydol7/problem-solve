#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;
	int N;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> N;
        int temp;                    
        vector<int> v;
        int max = 0;
        long long money = 0;
        for (int i = 0; i < N; i++) {
            cin >> temp;
            v.push_back(temp);
        }
        reverse(v.begin(), v.end());
        for (auto iter = v.begin(); iter != v.end(); iter++) {
            if (*iter >= max) max = *iter;
            else {
            	money += max - *iter;
            }
        }
		cout << "#" << test_case << " " << money << "\n";
	}
	return 0;
}