#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int N;
vector<tuple<int,int,int>> arr;
map<int,int> dp;
int answer;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        arr.push_back({b,a,c});
    }
    for(int i=0; i<N; i++){
        int end = get<0>(arr[i]);
        int start = get<1>(arr[i]);
        int cost = get<2>(arr[i]);
        
        auto it = dp.upper_bound(start);
        if(it != dp.begin()){
            it--;
        }
        if(it->first == start){
            it--;
        }
        int preMax = (it->first >= start) ? 0 : it->second;
        dp[end] = max(dp[end], preMax + cost);
        answer = max(answer,dp[end]);

    }

    
    cout << answer;
    

    return 0;
}
