#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> graph;
bool visited[1001];
int x1[1001];
int answer;
int xCount[1001];


void list(){
    for(int i=0; i<n; i++){
        if(!visited[x1[i]]){
            visited[x1[i]]= true;
            int small=10001;
            int minAnswer;
            for(auto ak : graph[x1[i]]){
                if(xCount[ak] < small){
                    small = xCount[ak];
                    minAnswer = ak;
                }
            }
            visited[minAnswer] = true;
            answer++;
        }
        
        
    }
}

int main() {
    cin >> n;
    graph.resize(1001);
    for (int i = 0; i < n; i++) {
        int a,b;
        cin >> a >> b;
        xCount[a]++;
        xCount[b]++;
        x1[i] = a;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    list();

    cout << answer;

    

    return 0;
}
