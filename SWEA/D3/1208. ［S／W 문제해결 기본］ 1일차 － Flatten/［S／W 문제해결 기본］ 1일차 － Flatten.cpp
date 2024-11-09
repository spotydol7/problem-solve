#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
    int dump, temp;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		vector<int> box;
        int ans;
        cin >> dump;
        for (int i = 0; i < 100; i++) {
        	cin >> temp;
            box.push_back(temp);
        }
        
        for (int i = 0; i < dump; i++) {
        	sort(box.begin(), box.end());
            box[99]--;
            box[0]++;
        }
        sort(box.begin(), box.end());
        ans = box[99] - box[0];
        cout << "#" << test_case << ' ' << ans << endl;
	}
	return 0;
}