#include<iostream>
#include<set>

using namespace std;

int sudoku[10][10];

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        for (int i = 0; i < 9; i++) {
        	for (int j = 0; j < 9; j++) {
            	cin >> sudoku[i][j];
            }
        }
        
        int ans = 1;
        for (int i = 0; i < 9; i++) {
            set<int> s;
        	for (int j = 0; j <9; j++) {
            	s.insert(sudoku[i][j]);
            }
            if (s.size() < 9) {
            	ans = 0;
                break;
            }
        }
        
        for (int i = 0; i < 9; i++) {
            set<int> s;
        	for (int j = 0; j <9; j++) {
            	s.insert(sudoku[j][i]);
            }
            if (s.size() < 9) {
            	ans = 0;
                break;
            }
        }
        
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                set<int> s;
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
						s.insert(sudoku[i + k][j + l]);
                    }
                }
                if (s.size() < 9) {
                	ans = 0;
                    break;
                }
            }
        }
        
        cout << '#' << test_case << ' ' << ans << endl;
	}
	return 0;
}