#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int N, M;
int coin[100];
int dp[10001];

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> coin[i];
    }
    for(int i=0; i<=M; i++){
        dp[i] = INT_MIN;
    }

    dp[0]=0;

    for(int i=1; i<=M; i++){
        for(int j=0; j<N; j++){
            if(i >= coin[j]){
                if(dp[i-coin[j]] != INT_MIN){
                    if(dp[i] == INT_MIN){
                        dp[i] =dp[i-coin[j]] + 1; 
                    }
                    else{
                        dp[i] = min(dp[i-coin[j]] + 1, dp[i]);
                    }
                }
               
                
            }
        }
    }
    cout << dp[M];
    

    return 0;
}
