#include <iostream>
#include <queue>

using namespace std;

int n;
int r, c;
int arr[100][100];
bool visited [100][100];

void dfs(int a, int b){

    cout << arr[a][b] << " ";
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};

    visited[a][b] = true;

    for(int i=0; i<4; i++){
        int x = a + dx[i];
        int y = b + dy[i];
        if(arr[a][b] < arr[x][y] && x>=0 && x <n && y>=0 && y <n){
            dfs(x,y);
            break;

        }
    }
    
}

int main() {
    cin >> n >> r >> c;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    dfs(r-1,c-1);

    return 0;
}
