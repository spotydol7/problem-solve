#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int rows = arr1.size();
    int cols = arr2[0].size();
    int common = arr2.size();

    
    vector<vector<int>> answer(rows, vector<int>(cols, 0));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            for (int k = 0; k < common; k++) {
                answer[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    return answer;
}