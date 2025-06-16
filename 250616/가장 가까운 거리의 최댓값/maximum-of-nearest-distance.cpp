#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int n, m;
int a, b, c;
vector<pair<int, int>> graph[10001];
int distA[10001], distB[10001], distC[10001];

void dijkstra(int source, int dist[]) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dist[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (dist[now] < cost) continue;

        for (auto [next, weight] : graph[now]) {
            if (dist[next] > dist[now] + weight) {
                dist[next] = dist[now] + weight;
                pq.push({dist[next], next});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    cin >> a >> b >> c;

    for (int i = 0; i < m; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        graph[u].push_back({v, t});
        graph[v].push_back({u, t});
    }

    dijkstra(a, distA);
    dijkstra(b, distB);
    dijkstra(c, distC);

    int answer = 0;
    for (int i = 1; i <= n; i++) {
        int minAnswer = min({distA[i], distB[i], distC[i]});
        if (minAnswer != INF && answer < minAnswer) {
            answer = minAnswer;
        }
    }

    cout << answer;
    return 0;
}
