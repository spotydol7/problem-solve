#include <iostream>
using namespace std;
// memoization

int fibarr[500];

int fibonacci(int n) {
    if (n == 0) {
        fibarr[0] = 0;
        return 0;
    }
    else if (n == 1) {
        fibarr[1] = 1;
        return 1;
    }
    if (fibarr[n] != 0){
        return fibarr[n];
    }
    else if (fibarr[n] == 0) {
        fibarr[n] = fibonacci(n - 1) + fibonacci(n - 2);
        return fibarr[n];
    }
}

int main()
{
    int t,n;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;
        if (n == 0)
            cout << "1 0" << '\n';
        else {
            fibonacci(n);
            cout << fibarr[n - 1] << " " << fibarr[n] << '\n';
        }
    }

    return 0;
}