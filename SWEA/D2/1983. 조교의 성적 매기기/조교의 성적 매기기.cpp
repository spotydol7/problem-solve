#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

string grade[10] = {"A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0"};

bool compare1(pair<double, int> a, pair<double, int> b) {
	return a.first > b.first; // 내림차순
}

int main(int argc, char** argv)
{
	int test_case;
	int T, n, k;

	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> n >> k;
        vector<pair<double, int>> v;
        for (int i = 1; i <= n; i++) {
        	int mid, fin, hw;
            cin >> mid >> fin >> hw;
            double score = 0.35 * mid + 0.45 * fin + 0.2 * hw;
            
            v.push_back(make_pair(score, i));
        }
        sort(v.begin(), v.end(), compare1);
        
        int temp, ans;
        for (int i = 0; i < n; i++) {
        	if (v[i].second == k) {
            	temp = i;
                ans = temp / (n / 10);
            }
        }
        
        cout << '#' << test_case << ' ' << grade[ans] << endl;
        
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}