#include <iostream>

using namespace std;

int N;
int M[1000];
pair<int,int> dp[1000];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> M[i];
    }
    dp[0] = {1,M[0]};

    for(int i=1; i<N; i++){
        if(dp[i-1].second >= M[i]){
            dp[i] = dp[i-1];
        }
        else{
            dp[i] = {(dp[i-1].first)+1 , M[i]};
        }
    }
    
    cout << dp[N-1].first;

    return 0;
}
