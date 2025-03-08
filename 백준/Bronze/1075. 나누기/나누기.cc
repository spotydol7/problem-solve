#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int N, F;
    cin >> N >> F;
    int base = N - (N % 100);
    for(int i = 0; i < 100; i++){
        if((base + i) % F == 0){
            printf("%02d", i);
            break;
        }
    }
    return 0;
}
