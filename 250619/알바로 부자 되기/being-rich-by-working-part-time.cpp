#include <iostream>
#include <vector>
#include <tuple>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    vector<tuple<int,int,int>> arr; // end, start, cost

    for (int i=0; i<N; i++) {
        int s,e,c; cin >> s >> e >> c;
        arr.emplace_back(e, s, c);
    }

    sort(arr.begin(), arr.end()); // 종료시간 기준 정렬

    map<int,int> dp; // 종료시간 -> 최대 이익
    dp[0] = 0;
    int answer = 0;

    for (auto& [end, start, cost] : arr) {
        // start보다 작거나 같은 최대 종료시간을 찾기 위해 lower_bound 후 --it
        auto it = dp.lower_bound(start);
        if (it == dp.begin()) {
            // 시작시간 이전에 작업 없음
            it = dp.end();
        } else {
            --it;
        }
        int preMax = (it == dp.end()) ? 0 : it->second;

        int val = preMax + cost;

        // val이 현재 dp에서 마지막 최대값보다 크면 업데이트
        if (val > prev(dp.end())->second) {
            dp[end] = val;
            answer = max(answer, val);
        } else {
            // 이미 더 큰 값이 있어서 갱신 안 함
            // 하지만 dp[end]가 존재하면 max로 갱신 (중복 end 시간)
            if(dp.count(end)) {
                if(dp[end] < val){
                    dp[end] = val;
                    answer = max(answer, val);
                }
            }
        }
    }

    cout << answer << "\n";

    return 0;
}
