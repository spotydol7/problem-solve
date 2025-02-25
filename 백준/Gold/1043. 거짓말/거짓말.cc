#include <iostream>
using namespace std;
// 자신의 그룹이 어디에 속해있는지 리턴
int findParent(int parent[], int x){
    if(x != parent[x])
        return parent[x] = findParent(parent, parent[x]);
    else
        return parent[x];
}

// x와 y를 같은 그룹으로 만들어줌
void merge(int parent[], int x, int y){
    int px = findParent(parent, parent[x]);
    int py = findParent(parent, parent[y]);
    if(px != py){
        if(px < py)
            parent[py] = parent[px];
        else
            parent[px] = parent[py];
    }
}
int main(){
    int n, m;
    cin >> n >> m;
 
    int known;
    cin >> known; 
    
    int parent[53]; // 어느 그룹에 속해 있는지 
    
    for(int i = 0; i <= n; i++)
        parent[i] = i; // 각자 자신의 그룹으로 먼저 분류
    
    int temp; // 진실을 아는 사람: ㄱ-
    for(int i = 0; i < known; i++){
        cin >> temp;
        parent[temp] = 0; // 0군의 삶
    }
 
    int Pnum;
    int temp2;
 
    int arr[53][53]; // 파티번호, 파티 사람 번호
    int arrsiz[53]; // 각 파티의 인원수 저장
    for(int i = 0; i < m; i++){
        cin >> Pnum; // 파티에 오는 사람 수 
        cin >> temp; // 파티에 오는 첫번째 사람
        arrsiz[i] = Pnum; // 각 파티의 인원 수 저장
        arr[i][0] = temp; 
        // 첫번째 사람만 올 경우 혼자 오는 것이기 때문에
        // 다른 사람과 그룹을 합치지 않아도 돼서 분류
        for(int j = 1; j < Pnum; j++){
            cin >> temp2; // 파티에 오는 사람 번호
            arr[i][j] = temp2; // 파티에 오는 사람 번호 저장
            merge(parent, temp ,temp2); // 파티에 오는 사람 그룹 합침
        }
    }
    int answer = 0;

    for(int i = 0; i < m; i++){
        for(int j=0; j < arrsiz[i]; j++){
            if(findParent(parent, parent[arr[i][j]]) == 0){
                answer++;
                break;
            }
        }
    }
    cout << m - answer;
    return 0;
}
