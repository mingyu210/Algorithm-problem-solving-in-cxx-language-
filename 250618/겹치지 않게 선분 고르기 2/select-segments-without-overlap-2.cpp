#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int,int>> graph;
int dp[1001];
int answer;



int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a,b;
        cin >> a >> b;
        graph.push_back({a,b});
    }
    sort(graph.begin(), graph.end());
    dp[0] = 1;
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(graph[j].second < graph[i].first){
                dp[i] = max(dp[j]+1,dp[i]);
            }
        }
    }
    for(int i=0; i<n; i++){
        answer = max(answer,dp[i]);
    }

    cout << answer;

    return 0;
}
