#include <iostream>

using namespace std;

int n, m;
int from[100000], to[100000], weight[100000];
int A, B;
int graph[1001][1001];
bool visited[1001];
int dist[1001];

void dijkstra(int a){
    for(int i=1; i<=n; i++){
        dist[i] = 10000001;
    }
    dist[a] = 0;

    for(int i=1; i<=n; i++){
        int min_index = -1;
        for(int j=1; j<=n; j++){
            if(visited[j]){
                continue;
            }
            if(min_index == -1 || dist[min_index] > dist[j]){
                min_index = j;
            }
        }
        visited[min_index] = true;

        for(int j=1; j<=n; j++){
            if(graph[min_index][j] == 0){
                continue;
            }
            dist[j] = min(dist[j] , dist[min_index] + graph[min_index][j]);
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i] >> weight[i];
        graph[from[i]][to[i]] = weight[i];
        graph[to[i]][from[i]] = weight[i];
    }

    cin >> A >> B;

    dijkstra(A);
    cout << dist[B];


    

    return 0;
}
