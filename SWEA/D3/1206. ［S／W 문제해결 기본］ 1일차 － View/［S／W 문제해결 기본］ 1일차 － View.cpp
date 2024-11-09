#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
    int N;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        vector<int> height;
        int temp;
        int cnt = 0;
        cin >> N;
        
        for (int i = 0; i < N; i++) {
        	cin >> temp;
            height.push_back(temp);
        }
        
        for (int i = 0; i < height.size(); i++) {
        	if (height[i] > height[i + 1] && height[i] > height[i + 2] && height[i] > height[i - 1] && height[i] > height[i - 2]) {
            	int max1 = height[i + 1] > height[i + 2] ? height[i + 1] : height[i + 2];
                int max2 = height[i - 1] > height[i - 2] ? height[i - 1] : height[i - 2];
                int max = max1 > max2 ? max1 : max2;
                cnt += height[i] - max;
            }
        }
        
        cout << "#" << test_case << ' ' << cnt << '\n';
    }
	return 0;
}