#include <iostream>
using namespace std;

int P, Q, A, B;

int main() {
    cin >> P >> Q >> A >> B;
    if (P < Q) cout << P * A + (Q - P) * B;
    else cout << Q * A;
}