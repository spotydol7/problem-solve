#include<iostream>

using namespace std;

int n;
int ans = 0;
int plane[16];
int visited[16];

bool isPromising(int queen) {
	for (int i = 0; i < queen; i++) {
    	if (visited[queen] == visited[i] || queen - i == abs(visited[queen] - visited[i])) {
        	return false;
        }
    }
    return true;
}

void dfs(int queen) {
    if (queen == n) {
        ans++;
        return;
    }
    for (int i = 0; i < n; i++) {
    	visited[queen] = i;
        if (isPromising(queen)) {
        	dfs(queen + 1);
        }
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> n;
        ans = 0;
        for (int i = 0; i < 16; i++) {
        	plane[i] = 0;
            visited[i] = 0;
        }
        dfs(0);
        cout << "#" << test_case << ' ' << ans << endl;
	}
	return 0;
}