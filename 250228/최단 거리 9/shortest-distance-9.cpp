#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int from[100000], to[100000], weight[100000];
int A, B;
int graph[1001][1001];
bool visited[1001];
int path[1001];
int dist[1001];


void dijkstra(int a){
    
    for(int i=1; i<=n; i++){
        dist[i] = 1000000;
    }
    dist[a] = 0;

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
            if(dist[j] > dist[min_idex] + graph[min_idex][j]) {
                dist[j] = dist[min_idex] + graph[min_idex][j];
                path[j] = min_idex;
    }
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
    
    int x = B;
    vector<int> vertices;
    vertices.push_back(x);
    while(x!=A){
        x = path[x];
        vertices.push_back(x);
    }
    cout << dist[B] << endl;
    for(int i = (int) vertices.size() - 1; i >= 0; i--){
        cout << vertices[i] << " ";
    }
        

    return 0;
}
