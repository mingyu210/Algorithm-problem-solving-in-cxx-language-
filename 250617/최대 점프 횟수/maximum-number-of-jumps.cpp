#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1000];
int dp[1000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i] = -1; // 초기화: 도달 불가능
    }

    dp[0] = 0; // 시작점은 점프 0회

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] != -1 && j + arr[j] >= i) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // 최대 점프 횟수는 도달 가능한 곳 중 가장 큰 dp[i]
    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] != -1) {
            answer = max(answer, dp[i]);
        }
    }

    cout << answer << endl;
    return 0;
}
