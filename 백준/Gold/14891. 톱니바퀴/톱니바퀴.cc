#include <bits/stdc++.h>
using namespace std;

void cw(int n);
void ccw(int n);

int arr1[3][3];
int arr2[3][3];
int arr3[3][3];
int arr4[3][3];
int rotation[4];

int left(int n) {
    if (n == 1) return arr1[1][0];
    if (n == 2) return arr2[1][0];
    if (n == 3) return arr3[1][0];
    if (n == 4) return arr4[1][0];
    return 0;
}

int right(int n) {
    if (n == 1) return arr1[1][2];
    if (n == 2) return arr2[1][2];
    if (n == 3) return arr3[1][2];
    if (n == 4) return arr4[1][2];
    return 0;
}

void check(int n, int d) {
    n--;
    rotation[n] = d;
    for (int i = n; i > 0; i--) { // 왼쪽
        if (left(i + 1) != right(i)) {
            rotation[i - 1] = -rotation[i];
        }
        else break;
    }
    for (int i = n; i < 3; i++) { // 오른쪽
        if (right(i + 1) != left(i + 2)) {
            rotation[i + 1] = -rotation[i];
        }
        else break;
    }
}

void cw(int n) {
    if (n == 1) {
        int temp = arr1[0][0];
        arr1[0][0] = arr1[1][0];
        arr1[1][0] = arr1[2][0];
        arr1[2][0] = arr1[2][1];
        arr1[2][1] = arr1[2][2];
        arr1[2][2] = arr1[1][2];
        arr1[1][2] = arr1[0][2];
        arr1[0][2] = arr1[0][1];
        arr1[0][1] = temp;
    }
    else if (n == 2) {
        int temp = arr2[0][0];
        arr2[0][0] = arr2[1][0];
        arr2[1][0] = arr2[2][0];
        arr2[2][0] = arr2[2][1];
        arr2[2][1] = arr2[2][2];
        arr2[2][2] = arr2[1][2];
        arr2[1][2] = arr2[0][2];
        arr2[0][2] = arr2[0][1];
        arr2[0][1] = temp;
    }
    else if (n == 3) {
        int temp = arr3[0][0];
        arr3[0][0] = arr3[1][0];
        arr3[1][0] = arr3[2][0];
        arr3[2][0] = arr3[2][1];
        arr3[2][1] = arr3[2][2];
        arr3[2][2] = arr3[1][2];
        arr3[1][2] = arr3[0][2];
        arr3[0][2] = arr3[0][1];
        arr3[0][1] = temp;
    }
    else {
        int temp = arr4[0][0];
        arr4[0][0] = arr4[1][0];
        arr4[1][0] = arr4[2][0];
        arr4[2][0] = arr4[2][1];
        arr4[2][1] = arr4[2][2];
        arr4[2][2] = arr4[1][2];
        arr4[1][2] = arr4[0][2];
        arr4[0][2] = arr4[0][1];
        arr4[0][1] = temp;
    }
}

void ccw(int n) {
    if (n == 1) {
        int temp = arr1[0][0];
        arr1[0][0] = arr1[0][1];
        arr1[0][1] = arr1[0][2];
        arr1[0][2] = arr1[1][2];
        arr1[1][2] = arr1[2][2];
        arr1[2][2] = arr1[2][1];
        arr1[2][1] = arr1[2][0];
        arr1[2][0] = arr1[1][0];
        arr1[1][0] = temp;
    }
    else if (n == 2) {
        int temp = arr2[0][0];
        arr2[0][0] = arr2[0][1];
        arr2[0][1] = arr2[0][2];
        arr2[0][2] = arr2[1][2];
        arr2[1][2] = arr2[2][2];
        arr2[2][2] = arr2[2][1];
        arr2[2][1] = arr2[2][0];
        arr2[2][0] = arr2[1][0];
        arr2[1][0] = temp;
    }
    else if (n == 3) {
        int temp = arr3[0][0];
        arr3[0][0] = arr3[0][1];
        arr3[0][1] = arr3[0][2];
        arr3[0][2] = arr3[1][2];
        arr3[1][2] = arr3[2][2];
        arr3[2][2] = arr3[2][1];
        arr3[2][1] = arr3[2][0];
        arr3[2][0] = arr3[1][0];
        arr3[1][0] = temp;
    }
    else {
        int temp = arr4[0][0];
        arr4[0][0] = arr4[0][1];
        arr4[0][1] = arr4[0][2];
        arr4[0][2] = arr4[1][2];
        arr4[1][2] = arr4[2][2];
        arr4[2][2] = arr4[2][1];
        arr4[2][1] = arr4[2][0];
        arr4[2][0] = arr4[1][0];
        arr4[1][0] = temp;
    }
}

int main() {
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d", 
    &arr1[0][1], &arr1[0][2], &arr1[1][2], 
    &arr1[2][2],              &arr1[2][1], 
    &arr1[2][0], &arr1[1][0], &arr1[0][0]);

    scanf("%1d%1d%1d%1d%1d%1d%1d%1d", 
    &arr2[0][1], &arr2[0][2], &arr2[1][2], 
    &arr2[2][2],              &arr2[2][1], 
    &arr2[2][0], &arr2[1][0], &arr2[0][0]);

    scanf("%1d%1d%1d%1d%1d%1d%1d%1d", 
    &arr3[0][1], &arr3[0][2], &arr3[1][2], 
    &arr3[2][2],              &arr3[2][1], 
    &arr3[2][0], &arr3[1][0], &arr3[0][0]);

    scanf("%1d%1d%1d%1d%1d%1d%1d%1d", 
    &arr4[0][1], &arr4[0][2], &arr4[1][2], 
    &arr4[2][2],              &arr4[2][1], 
    &arr4[2][0], &arr4[1][0], &arr4[0][0]);

    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        memset(rotation, 0, sizeof(rotation));

        int n, dir;
        cin >> n >> dir;
        check(n, dir);

        for (int j = 0; j < 4; j++) {
            if (rotation[j] == 1) {
                cw(j + 1);
            }
            else if (rotation[j] == -1) {
                ccw(j + 1);
            }
        } 
    }

    int ans = arr1[0][1] + 2 * arr2[0][1] + 4 * arr3[0][1] + 8 * arr4[0][1];
    cout << ans << '\n';
}