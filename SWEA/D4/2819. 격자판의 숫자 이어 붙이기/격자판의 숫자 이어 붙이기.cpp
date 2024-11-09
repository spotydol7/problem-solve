#include<iostream>
#include<vector>
#include<set>

using namespace std;

string plane[4][4];
set<string> ans;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
void dfs(int x, int y, string str) {
    if (str.length() == 7) {
        ans.insert(str);
        return;
    }
    for (int i = 0; i < 4; i++) {
    	int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 4 || ny >= 4 || nx < 0 || ny < 0 ) continue;
        dfs(nx, ny, str + plane[ny][nx]);
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		for (int i = 0; i < 4; i++) {
        	for (int j = 0; j < 4; j++) {
            	cin >> plane[i][j];
            }
        }
        
        ans.clear();
        for (int i = 0; i < 4; i++) {
        	for (int j = 0; j < 4; j++) {
				dfs(j, i, "");
            }
        }
        
        cout << "#" << test_case << ' ' << ans.size() << endl;
	}
	return 0;
}