#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int n, m;
int from[100000], to[100000], weight[100000];
int A, B;
vector<pair<int,int>> graph[1001];
priority_queue<pair<int,int>> pq;
int graph2[1001][1001];

int dist[1001];

int main() {
    cin >> n >> m;

    vector<tuple<int,int,int>> edge;
    edge.push_back({-1,-1,-1});
    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i] >> weight[i];
        edge.push_back({to[i] , from[i] , weight[i]});
    }
    cin >> A >> B;
    for(int i=1; i<=m; i++){
        int x,y,z;
        tie(x,y,z) = edge[i];
        graph[x].push_back({y,z});
        graph[y].push_back({x,z});
        graph2[x][y] = z;
        graph2[y][x] = z;
    }

    for(int i=1; i<=n; i++){
        dist[i] = 100000;
    }
    dist[B] = 0;

    pq.push({-0,B});

    while(!pq.empty()){
        int min_dist, min_index;
        tie(min_dist,min_index) = pq.top();
        pq.pop();

        min_dist = -min_dist;

        if(min_dist != dist[min_index]){
            continue;
        }

        for(int j=0; j<(int)graph[min_index].size(); j++){
            int target_index, target_dist;
            tie(target_index, target_dist) = graph[min_index][j];

            int new_dist = dist[min_index] + target_dist;

            if(dist[target_index] > new_dist){
                dist[target_index] = new_dist;
                pq.push({-new_dist, target_index});
            }
        }
    }

    cout << dist[A] << endl;

    int x = A;
    cout << x << " ";
    
    while(x != B){
        for(int i = 1; i <= n; i++) {
            if(graph2[i][x] == 0)
                continue;
        
       
            if(dist[i] + graph2[i][x] == dist[x]) {
                x = i;
                break;
            }
        }
        cout << x << " ";
    }
    
   
    return 0;
}
