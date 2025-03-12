#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m, d;
int board[16][16];   // 원본 보드
int temp[16][16];    // 시뮬레이션 시 사용할 보드 복사본

// 시뮬레이션: archers 배열에 3명의 궁수(0-indexed 열 번호)가 들어 있음.
// 매 턴마다 각 궁수가 공격 대상을 선택한 후, 동시에 공격하고, 적을 아래로 이동합니다.
int simulate(int archers[3]) {
    int killCount = 0;
    // 원본 board를 temp에 복사
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            temp[i][j] = board[i][j];

    // 최대 n번의 턴 (모든 적이 성 앞으로 내려오거나 제거됨)
    for (int turn = 0; turn < n; turn++) {
        bool hit[16][16] = { false };  // 이번 턴에 공격받을 적 위치를 기록

        // 각 궁수별로 공격 대상 선정
        for (int a = 0; a < 3; a++) {
            int bestDist = d + 1;
            int targetR = -1, targetC = -1;
            // 모든 적에 대해 검사 (전체 보드 순회)
            for (int i = n - 1; i >= 0; i--) {
                for (int j = 0; j < m; j++) {
                    if (temp[i][j] == 1) {
                        int dist = (n - i) + abs(archers[a] - j);
                        if (dist <= d) {
                            // 거리가 짧거나, 거리가 같으면 더 왼쪽이면 갱신
                            if (dist < bestDist || (dist == bestDist && j < targetC)) {
                                bestDist = dist;
                                targetR = i;
                                targetC = j;
                            }
                        }
                    }
                }
            }
            // 유효한 목표가 있다면 이번 턴 공격 대상에 추가
            if (targetR != -1)
                hit[targetR][targetC] = true;
        }

        // 공격 대상에 있는 적을 제거
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (hit[i][j] && temp[i][j] == 1) {
                    killCount++;
                    temp[i][j] = 0;
                }
            }
        }

        // 적 이동: 모든 적이 한 행 아래로 이동, 가장 아래 행은 성에 도달하므로 사라짐
        for (int i = n - 1; i > 0; i--) {
            for (int j = 0; j < m; j++) {
                temp[i][j] = temp[i - 1][j];
            }
        }
        // 첫 행은 빈 칸으로 채움
        for (int j = 0; j < m; j++) {
            temp[0][j] = 0;
        }
    }
    return killCount;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m >> d;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }
    
    int best = 0;
    int archers[3];
    // m의 열 중에서 3개의 궁수 위치를 3중 for문으로 선택 (조합: mC3)
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            for (int k = j + 1; k < m; k++) {
                archers[0] = i;
                archers[1] = j;
                archers[2] = k;
                best = max(best, simulate(archers));
            }
        }
    }
    cout << best << "\n";
    return 0;
}
