#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

#define MAX_N 20000

using namespace std;

int n, m, k;
int from[300000], to[300000], weight[300000];
vector<pair<int,int>> graph[MAX_N +1];
priority_queue<pair<int, int>> pq;


int dist[MAX_N + 1];

int main() {
    cin >> n >> m;
    cin >> k;

    vector<tuple<int,int,int>> edge;
    edge.push_back({-1,-1,-1});
    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i] >> weight[i];
        edge.push_back({from[i],to[i],weight[i]});
    }

    for(int i=1; i<=m; i++){
        int x, y ,z;
        tie(x,y,z) = edge[i];
        graph[x].push_back(make_pair(y,z));
        graph[y].push_back(make_pair(x,z));
    }
    
    for(int i=1; i<=n; i++){
        dist[i] = 1000000;
    }
    dist[k] = 0;

    pq.push(make_pair(-0,k));

    while(!pq.empty()){
        int min_dist, min_index;
        tie(min_dist, min_index) = pq.top();
        pq.pop();

        min_dist = -min_dist;

        if(min_dist != dist[min_index]){
            continue;
        }

        for(int j =0; j<(int) graph[min_index].size(); j++){
            int target_index, target_dist;
            tie(target_index, target_dist) = graph[min_index][j];
            
            int new_dist = dist[min_index] + target_dist;

            if(dist[target_index] > new_dist){
                dist[target_index] = new_dist;
                pq.push(make_pair(-new_dist, target_index));
            }
        }
    }

    for(int i=1; i<=n; i++){
        if(dist[i] == 1000000){
            cout << -1 << endl;
        }
        else{
            cout << dist[i] << endl;
        }
        
    }

    

    return 0;
}
