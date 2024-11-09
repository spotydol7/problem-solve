#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	int n, temp;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
        vector<vector<int>> plane;
        int rowsum = 0;
        int rowmax = 0;
        int colsum = 0;
        int colmax = 0;
        int diagsum1 = 0;
        int diagsum2 = 0;
		cin >> n;
        for(int i = 0; i < 100; i++) {
            vector<int> row;
        	for (int j = 0; j < 100; j++) {
            	cin >> temp;
                row.push_back(temp);
                rowsum += temp;
            }
            if (rowsum > rowmax) rowmax = rowsum;
            rowsum = 0;
            plane.push_back(row);
        }
        
        for(int i = 0; i < 100; i++) {
        	for(int j = 0; j < 100; j++) {
            	colsum += plane[j][i];
            }
            if (colsum > colmax) colmax = colsum;
            colsum = 0;
        }
        
        for(int i = 0; i < 100; i++) {
        	diagsum1 += plane[i][i];
        }
        
        for (int i = 99; i >= 0; i--) {
        	diagsum2 += plane[i][i];
        }
        int max1 = rowmax > colmax ? rowmax : colmax;
        int max2 = diagsum1 > diagsum2 ? diagsum1 : diagsum2;
        int ans = max(max1,max2);
        cout << "#" << test_case << ' ' << ans << endl;
	}
	return 0;
}