#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
int grid[50][50];
int bigK;
int answerK =1;
int answer;
bool visited[50][50];

void dfs2(int k, int x, int y){
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    visited[x][y] = true;

    for(int i=0; i<4; i++){
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if(new_x>=0 && new_x < N && new_y>=0 && new_y < M && !visited[new_x][new_y] && grid[new_x][new_y] > k){
            dfs2(k,new_x,new_y);
        }
    }


}


int dfs(int k){
    int num = 0;
    for(int i=0; i<N; i++){
        for(int j =0; j<M; j++){
            if(!visited[i][j] && grid[i][j] > k){
                num++;
                dfs2(k,i,j);
            }
        }
    }
    return num;
}   


int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
            bigK = max(grid[i][j] , bigK);
        }
    }

    for(int i=1; i<bigK; i++){
        int cq = dfs(i);
        if(answer < cq){
            answer = cq;
            answerK = i;
        }
        memset(visited, 0, sizeof(visited));
    }

    cout << answerK << " " << answer;

    return 0;
}
