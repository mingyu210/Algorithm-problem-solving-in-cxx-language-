#include <iostream>

using namespace std;

int n, m;
int r, c;
char directions[10000];
int answer = 0;
int grid[101][101];
int dice[6];

int main() {
    cin >> n >> m >> r >> c;

    for (int i = 0; i < m; i++) {
        cin >> directions[i];
    }
    r--;
    c--;
    dice[0] = 6; //아래
    dice[1] = 1; // 위
    dice[2] = 4; // 왼쪽
    dice[3] = 3; // 오른쪽
    dice[4] = 5; // 앞
    dice[5] = 2; // 뒤
    grid[r][c] = 6;
    for(int i=0; i<m; i++){
        if(directions[i] == 'L'){
            if(c-1 >=0){
                c--;
                int temp = dice[0];
                dice[0] = dice[2];
                dice[2] = dice[1];
                dice[1] = dice[3];
                dice[3] = temp;
                grid[r][c] = dice[0];
            }
        }
        else if(directions[i] == 'R'){
            if(c+1 <n){
                c++;
                int temp = dice[0];
                dice[0] = dice[3];
                dice[3] = dice[1];
                dice[1] = dice[2];
                dice[2] = temp;
                grid[r][c] = dice[0];
            }

        }
        else if(directions[i] == 'U'){
            if(r-1>=0){
                r--;
                int temp = dice[0];
                dice[0] = dice[4];
                dice[4] = dice[1];
                dice[1] = dice[5];
                dice[5] = temp;
                grid[r][c] = dice[0];
            }
            
        }
        else if(directions[i] == 'D'){
            if(r+1 <n){
                r++;
                int temp = dice[0];
                dice[0] = dice[5];
                dice[5] = dice[1];
                dice[1] = dice[4];
                dice[4] = temp;
                grid[r][c] = dice[0];
                
            }
            
        }
    }
    int answer = 0;
    for(int i=0; i<101; i++){
        for(int j=0; j<101; j++){
            answer += grid[i][j];
        }
    }
    cout << answer;

    

    return 0;
}
