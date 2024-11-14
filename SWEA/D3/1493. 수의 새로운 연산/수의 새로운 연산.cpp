#include<iostream>

using namespace std;

int arr[301][301];

int main(int argc, char** argv)
{
	int test_case;
	int T, p, q;
    
    int num = 1;
    for (int i = 1; i <= 300; i++) {
        arr[i][1] = num;
        num = num + i;
        for (int j = 2; j <= 300; j++) {
            arr[i][j] = arr[i][j - 1] + i + j - 1;
        }
    }
    
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> p >> q;
        
        int x1, y1, x2, y2;
        for (int i = 1; i <= 300; i++) {
        	for (int j = 1; j <= 300; j++) {
            	if (arr[i][j] == p) {
                    x1 = i;
                    y1 = j;
                }
                if (arr[i][j] == q) {
                	x2 = i;
                    y2 = j;
                }
            }
        }
        
        int x = x1 + x2;
        int y = y1 + y2;
        
        cout << '#' << test_case << ' ' << arr[x][y] << endl;
	}
	return 0;
}