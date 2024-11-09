#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T, N;
    int temp;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        vector<int> v;
        vector<int> ans;
		cin >> N;
        for(int i = 0; i < 2 * N; i++) {
        	cin >> temp;
            v.push_back(temp);
        }
        for (int i = 0; i < v.size(); i++) {
        	int sale = v[i];
            int origin = v[i] / 3;
            origin *= 4;
            for (int j = i + 1; j < v.size(); j++) {
            	if (v[j] == origin) {
                    v[j] = -1;
                    ans.push_back(sale);
                	break;
                }
            }
        }
        cout << "#" << test_case << " ";
        for (auto iter = ans.begin(); iter != ans.end(); iter++) {
        	cout << *iter << ' ';
        }
        cout << endl;
	}
	return 0;
}