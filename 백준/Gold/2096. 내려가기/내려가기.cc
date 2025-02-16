#include <bits/stdc++.h>
using namespace std;
long long N, dp_mx[4][2], dp_mn[4][2];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin>>N;
	for(int i=1; i<=N; i++) {
        int num1, num2, num3;
		cin>>num1>>num2>>num3;
		dp_mx[1][1]=num1+max(dp_mx[1][0], dp_mx[2][0]);
		dp_mn[1][1]=num1+min(dp_mn[1][0], dp_mn[2][0]);

		dp_mx[2][1]=num2+max({dp_mx[1][0], dp_mx[2][0], dp_mx[3][0]});
		dp_mn[2][1]=num2+min({dp_mn[1][0], dp_mn[2][0], dp_mn[3][0]});

		dp_mx[3][1]=num3+max(dp_mx[3][0], dp_mx[2][0]);
		dp_mn[3][1]=num3+min(dp_mn[3][0], dp_mn[2][0]);

		for(int i=1; i<=3; i++) {
			dp_mx[i][0]=dp_mx[i][1];
			dp_mn[i][0]=dp_mn[i][1];
		}
	}
	cout<<max({dp_mx[1][0], dp_mx[2][0], dp_mx[3][0]})<<" "<<min({dp_mn[1][0], dp_mn[2][0], dp_mn[3][0]});

}
