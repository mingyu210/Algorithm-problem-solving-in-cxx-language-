#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<tuple<int,int,int>> arr;
int dp[1001];
int answer;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        arr.push_back({b,a,c});
    }
    dp[0] = 0;
    for(int i=0; i<N; i++){
            dp[get<0>(arr[i])] = max(dp[get<1>(arr[i])-1] + get<2>(arr[i]), dp[get<0>(arr[i])]);
    }

    for(auto ass : arr){
        answer = max(answer, dp[get<0>(ass)]);
    }
    cout << answer;
    

    return 0;
}
