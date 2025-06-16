#include <iostream>

using namespace std;

int N;
int M[1000];
int dp[1000] = {1,};
int answer = 0;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> M[i];
    }


    for(int i=1; i<N; i++){
        for(int j=0; j<N; j++){
            if(M[i] > M[j] && i > j){
                if(dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                }
            }
        }
    }
    
    for(int i=0; i<N; i++){
        if(answer < dp[i]){
            answer = dp[i];
        }
    }

    cout << answer;

    return 0;
}
