#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int grid[51][51];
int dp[51][51];
int answer;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }
    
    dp[1][1] = 1;

    for(int i=2; i<=n; i++){
        for(int j=2; j<=m; j++){
            for(int x =1; x <i; x++){
                for(int y=1; y<j; y++){
                    if(dp[x][y] == 0){
                        continue;
                    }
                    if(grid[i][j] > grid[x][y]){
                        dp[i][j] = max(dp[x][y] + 1, dp[i][j]);
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            answer = max(answer, dp[i][j]);
        }
            
    cout << answer;
    

    return 0;
}
