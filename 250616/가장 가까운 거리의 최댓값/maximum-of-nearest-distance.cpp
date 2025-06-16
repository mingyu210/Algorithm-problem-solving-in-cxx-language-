#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int a, b, c;
int from[100000], to[100000], weight[100000];
int graph[10001][10001];
int distA[10001];
int distB[10001];
int distC[10001];
int visitedA[10001];
int visitedB[10001];
int visitedC[10001];
int answer = 0;


void dijkstra(int source, int dist[], int visited[]){
    for(int i=1; i<=n; i++){
        dist[i] = 10001;
    }
    dist[source] = 0;

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
        if(min_index == -1) break;
        visited[min_index] = true;

        for(int j=1; j<=n; j++){
            if(graph[min_index][j] == 0){
                continue;
            }
            dist[j] = min(dist[j], dist[min_index] + graph[min_index][j]);
        }
    }
}

int main() {
    cin >> n >> m;
    cin >> a >> b >> c;

    for (int i = 0; i < m; i++) {
        int u;
        int v;
        int t;
        cin >> u >> v >> t;
        graph[u][v] = t;
        graph[v][u] = t;
    }

    dijkstra(a,distA,visitedA);
    dijkstra(b,distB,visitedB);
    dijkstra(c,distC,visitedC);

    for(int i=1; i<n; i++){
       int minAnswer = min(min(distA[i], distB[i]), distC[i]); 
       if(minAnswer !=0 && answer < minAnswer){
        answer = minAnswer;
       }
    }

    cout << answer;
    return 0;
}
