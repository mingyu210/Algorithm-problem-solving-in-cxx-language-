#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M;
int coin[100];
int dp[10001];

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> coin[i];
    }

    dp[0] = 0;
    sort(coin, coin+N);
    for(int i=0; i<N; i++){
        for(int j=1; j<=M; j++){
            if(coin[i] % j == 0){
                dp[j] = max(dp[j], j/coin[i]);
            }
        }
    }
    for(int i=0; i<N; i++){
        for(int j=1; j<=M; j++){
            if(j-coin[i] >= 0 && dp[j - coin[i]] > 0)
                dp[j] = max(dp[j], dp[j - coin[i]]+1); 
        }
    }
    
    cout << dp[M];
    return 0;
}
