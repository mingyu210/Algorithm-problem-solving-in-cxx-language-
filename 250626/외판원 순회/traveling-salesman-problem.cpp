#include <iostream>
#include <climits>

using namespace std;

int n;
int A[11][11];
bool visited[11];
int realAnswer = INT_MAX;

void backTracking(int now, int cnt, int cost) {
    if (cnt == n) {
        if (A[now][1] != 0) {  // 마지막 도시에서 1번으로 돌아갈 수 있을 때만
            realAnswer = min(realAnswer, cost + A[now][1]);
        }
        return;
    }

    for (int next = 1; next <= n; next++) {
        if (!visited[next] && A[now][next] != 0) {  // 갈 수 있는 도시
            visited[next] = true;
            backTracking(next, cnt + 1, cost + A[now][next]);
            visited[next] = false;
        }
    }
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> A[i][j];
        }
    }

    visited[1] = true;
    backTracking(1, 1, 0);

    cout << realAnswer << endl;

    return 0;
}
