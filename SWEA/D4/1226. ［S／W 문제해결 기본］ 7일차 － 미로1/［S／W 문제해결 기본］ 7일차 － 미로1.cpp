#include <iostream>
#include <cstring>

using namespace std;

int arr[17][17];
int visited[17][17];

void floodfill(int x, int y) {
	if (x < 0 || x >= 16 || y < 0 || y >= 16) return;
    if (visited[y][x]) return;
    if (arr[y][x] != 0) return;
    
    visited[y][x] = 1;
    arr[y][x] = 3;
    
    floodfill(x + 1, y);
    floodfill(x - 1, y);
    floodfill(x, y + 1);
    floodfill(x, y - 1);
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	int n;
    int startx, starty;
    int endx, endy;
    int ans;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;
        for (int i = 0; i < 16; i++) {
        	for (int j = 0; j < 16; j++) {
            	scanf("%1d", &arr[i][j]);
                if (arr[i][j] == 2) {
                	startx = j;
                    starty = i;
                    arr[i][j] = 0;
                }
                if (arr[i][j] == 3) {
                	endx = j;
                    endy = i;
                    arr[i][j] = 0;
                }
            }
        }
        
        memset(visited, 0, sizeof(visited));
        floodfill(startx, starty);
        
        if (arr[endy][endx] == arr[starty][startx]) ans = 1;
        else ans  = 0;
        
        cout << "#" << test_case << ' '  << ans << endl;
	}
	return 0;
}