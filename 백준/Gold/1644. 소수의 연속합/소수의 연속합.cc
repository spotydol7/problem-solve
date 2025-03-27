#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> primes;
bool isPrime[4000001];

void getPrime(int n) {
    isPrime[0] = isPrime[1] = true;
    for (int i = 2; i * i <= n; i++) {
        if (!isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = true;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (!isPrime[i])
            primes.push_back(i);
    }
}

int main() {
    cin >> n;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    
    getPrime(n);
    
    int cnt = 0;
    int st = 0, en = 0;
    int sum = 0;
    
    while (true) { // 투포인터
        if (sum >= n) {
            sum -= primes[st++];
        } else {
            if (en == primes.size()) break;
            sum += primes[en++];
        }
        if (sum == n) cnt++;
    }
    
    cout << cnt;
    return 0;
}
