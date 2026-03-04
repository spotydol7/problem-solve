#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int cnt = 0;
    int temp = n;
    while (temp != 0) {
        if (temp % 2 == 1) cnt++;
        temp /= 2;
    }
    
    while(true) {
        temp = n + 1;
        int tempcnt = 0;
        while (temp != 0) {
            if (temp % 2 == 1) tempcnt++;
            temp /= 2;
        }
        
        if (tempcnt == cnt) {
            return n + 1;
        }
        
        n++;
    }
}