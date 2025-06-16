#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();
int N, M, A, B, C;

vector<vector<pair<int, int>>> graph;

// 다익스트라: 시작점에서 모든 정점까지 최단거리 계산
vector<int> dijkstra(int start) {
    vector<int> dist(N + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [curDist, u] = pq.top();
        pq.pop();

        if (curDist > dist[u]) continue;

        for (auto [v, cost] : graph[u]) {
            if (dist[v] > dist[u] + cost) {
                dist[v] = dist[u] + cost;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    cin >> A >> B >> C;

    graph.resize(N + 1);

    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w); // 무방향
    }

    // A, B, C 각각에서의 최단 거리 계산
    vector<int> distA = dijkstra(A);
    vector<int> distB = dijkstra(B);
    vector<int> distC = dijkstra(C);

    int answer = 0;

    for (int i = 1; i <= N; ++i) {
        int minDist = min({distA[i], distB[i], distC[i]});
        answer = max(answer, minDist);
    }

    cout << answer << '\n';
    return 0;
}
