#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
vector<int> problem;
int score[99999];

int main(int argc, char** argv)
{
	int test_case;
	int T, n;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> n;
        problem.clear();
        for (int i = 0; i < n; i++) {
        	int temp;
            cin >> temp;
            problem.push_back(temp);
        }
        memset(score, 0, sizeof(score));
        score[0] = 1;
        
        int sum = 0;
        for (int i = 0; i < n; i++) {
        	sum += problem[i];
            for (int j = sum; j >= 0 ; j--) {
            	if (score[j]) score[j + problem[i]] = 1;
            }
        }
        
        int ans = 0;
        for (int i = 0; i < sum + 1; i++) {
        	ans += score[i];
        }
        
        cout << '#' << test_case << ' ' << ans<< endl;
	}
	return 0;
}