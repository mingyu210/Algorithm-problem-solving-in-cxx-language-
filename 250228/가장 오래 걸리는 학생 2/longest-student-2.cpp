#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int N, M;
int i[100000], j[100000], d[100000];
vector<pair<int,int>> graph[1000001];
priority_queue<pair<int, int>> pq;
int answer = -1;



int main() {
    cin >> N >> M;

    vector<tuple<int,int,int>> edge;
    edge.push_back({-1,-1,-1});
    for (int k = 0; k < M; k++) {
        cin >> i[k] >> j[k] >> d[k];
        edge.push_back({j[k],i[k],d[k]});
    }

    for(int i=1; i<=M; i++){
        int x,y,z;
        tie(x,y,z) = edge[i];
        graph[x].push_back(make_pair(y,z));
    }

    int dist[1000001];
    for(int i=1; i<=N; i++){
        dist[i] = 1000000;
    }
    dist[N] = 0;

    pq.push(make_pair(-0,N));

    while(!pq.empty()){
        int min_dist, min_index;
        tie(min_dist, min_index) = pq.top();
        pq.pop();

        min_dist = -min_dist;

        if(min_dist != dist[min_index]){
            continue;
        }
        

        for(int i=0; i<(int)graph[min_index].size(); i++){
           int target_index, target_dist;
           tie(target_index,target_dist) = graph[min_index][i];

           int new_dist = dist[min_index]+ target_dist;

           if(dist[target_index] > new_dist){
                dist[target_index] = new_dist;
                pq.push({-new_dist, target_index});
           }
           
        }
    }

    for(int i=1; i<=N; i++){
        answer = max(answer,dist[i]);
    }
    cout << answer;
    
    


    

    return 0;
}
