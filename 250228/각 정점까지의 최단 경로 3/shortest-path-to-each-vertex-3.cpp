#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;
int from[1000], to[1000], weight[1000];
int graph[1001][1001];
int dist[1000];
bool visited[1000];


void dijkstra(){
    for(int i=1; i<=n; i++){
        dist[i] = 100000;
    }
    dist[1] = 0;

    for(int i=1; i<=n; i++){
        int min_idex = -1;
        for(int j=1; j<=n; j++){
            if(visited[j]){
                continue;
            }
            if(min_idex == -1 || dist[min_idex] > dist[j]){
                min_idex = j;
            }
        }
        visited[min_idex] = true;
        for(int j=1; j<=n; j++){
            if(graph[min_idex][j] ==0){
                continue;
            }
            dist[j] = min(dist[j], dist[min_idex] + graph[min_idex][j]);
        }
    }

}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i] >> weight[i];
        graph[from[i]][to[i]] = weight[i];
    }

    dijkstra();

    for(int i=2; i<=n; i++){
        if(dist[i] == 100000){
            cout << -1 << endl; 
        }
        else{
             cout << dist[i] << endl;
        }
    }
  
    

    return 0;
}
