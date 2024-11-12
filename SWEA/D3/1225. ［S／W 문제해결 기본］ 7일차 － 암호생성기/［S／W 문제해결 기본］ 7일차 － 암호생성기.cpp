#include <iostream>
#include <deque>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	int n;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;
        int temp;
        deque<int> dq;
        for (int i = 0; i < 8; i++) {
        	cin >> temp;
            dq.push_back(temp);
        }
        
        while (dq.back() != 0) {
        	for (int i = 1; i <= 5; i++) {
            	int temp = dq.front() - i;
                if (temp <=  0) {
                    temp = 0;
                    dq.pop_front();
                	dq.push_back(temp);
                    break;
                }
                dq.pop_front();
                dq.push_back(temp);
            }
        }
        cout << '#' << test_case << ' ';
        for (int i = 0; i < 8; i++) {
        	cout << dq[i] << ' ';
        }
        cout << endl;
	}
	return 0;
}