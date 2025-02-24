#include <iostream>

using namespace std;

int n, m, k;
int grid[100][100];

void down(int a, int b){
    for(int j=k; j < k+m; j++){
        grid[0][j] = 1;
    }
    for(int i=1; i<n; i++){
        bool flag = true;
        for(int j=k; j < k+m; j++){
            if(grid[i][k] == 1){
                flag = false;
            }
        }
        if(flag){
            for(int j=k; j < k+m; j++){
                grid[i][j] = 1;
            }
            for(int j=k; j < k+m; j++){
                grid[i-1][j] = 0;
            }

        }
        else{
            break;
        }
    }
}

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    m;
    k--;
    down(m,k);
   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
