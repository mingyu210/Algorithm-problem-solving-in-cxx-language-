#include <iostream>

using namespace std;

int n, m, r, c;
int grid[101][101];
int answer = 0;

void bomb(int k){
    int temp[101][101];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(grid[i][j] == 1){
                temp[i][j] = 1;
                if(i-k >=1){
                    temp[i-k][j] = 1;
                }
                if(i+k <=n){
                    temp[i+k][j] = 1;
                }
                if(j+k <=n){
                    temp[i][j+k] = 1;
                }
                if(j-k >=1){
                    temp[i][j-k] = 1;
                }
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            grid[i][j] = temp[i][j];
        }
    }
    
}

int main() {
    cin >> n >> m >> r >> c;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            grid[r][c] = 1;
        }
    }
    int bombTime = 0;
    while(m--){
        bombTime++;
        bomb(bombTime);
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(grid[i][j] == 1){
                answer++;
            }
        }
    }
    cout << answer;

    return 0;
}
