#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;
int from[1000], to[1000], weight[1000];
int graph[1001][1001]; // 1-based 인덱스를 위해 크기 증가
int dist[1001];
bool visited[1001];

void dijkstra(){
    for(int i=1; i<=n; i++){
        dist[i] = INT_MAX;  // 모든 거리를 무한대로 설정
    }
    dist[1] = 0;  // 출발점의 거리는 0

    for(int i=1; i<=n; i++){
        int min_index = -1;
        // 최소값을 가진 노드 찾기
        for(int j=1; j<=n; j++){
            if(visited[j]){
                continue;
            }
            if(min_index == -1 || dist[min_index] > dist[j]){
                min_index = j;
            }
        }
        
        visited[min_index] = true;

        // 최소값을 가진 노드에서 다른 노드로의 거리 계산
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

    // 그래프 초기화 (양방향일 경우)
    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i] >> weight[i];
        graph[from[i]][to[i]] = weight[i];
        graph[to[i]][from[i]] = weight[i];  // 무방향 그래프 처리
    }

    dijkstra();

    // 출력: 시작점은 제외하고 나머지 출력
    for(int i=2; i<=n; i++){
        if(dist[i] == INT_MAX){
            cout << -1 << endl;  // 도달할 수 없는 노드는 -1로 출력
        } else {
            cout << dist[i] << endl;
        }
    }

    return 0;
}
