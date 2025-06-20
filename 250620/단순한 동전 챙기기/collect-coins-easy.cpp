#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int N;
char grid[20][20];
vector<pair<int, int>> coinBoard;
vector<int> arr;
pair<int,int> start;
pair<int,int> destination;
int dist[20][20];
int answer = 10000;

int bfs(pair<int,int> first, pair<int,int> second){
    memset(dist, -1, sizeof(dist)); 
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    queue<pair<int,int>> q;

    q.push(first);
    dist[first.first][first.second] = 0;

    while(!q.empty()){
        auto [x,y] = q.front(); q.pop();

        for(int dir = 0; dir<4; dir++){
            int nx = x+dx[dir];
            int ny = y+dy[dir];

            if(nx >= 0 && nx < N && ny >= 0 && ny < N && dist[nx][ny] == -1){
                if(nx == second.first && ny == second.second){
                    return dist[x][y] + 1;
                }
                //else if (grid[nx][ny] == '#'){ // 이동 가능한 곳
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
               // }
            }
        }
    }

}

void backTracking(int start2, int num){
    if(num == 3){
        int minianswer = 0;
        for(int i = 0; i < 3; i++){
            if(i == 0){
                minianswer += bfs(start, coinBoard[arr[i]]);
            }
            else{
                minianswer += bfs(coinBoard[arr[i-1]], coinBoard[arr[i]]);
            }
        }
        minianswer += bfs(coinBoard[arr[2]], destination);

        if(answer > minianswer){
            answer = minianswer;
        }
        return;
    }

    for(int i = start2; i < (int)coinBoard.size(); i++){
        arr.push_back(i);
        backTracking(i + 1, num + 1);
        arr.pop_back();
    }
}

int main() {
    cin >> N;

    vector<tuple<int,int,int>> coins; // {value, x, y}

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
            if(grid[i][j] >= '1' && grid[i][j] <= '9'){
                coins.push_back({grid[i][j] - '0', i, j});
            }
            if(grid[i][j] == 'S'){
                start = {i,j};
            }
            if(grid[i][j] == 'E'){
                destination = {i,j};
            }
        }
    }

    sort(coins.begin(), coins.end()); // 코인 번호 기준 정렬

    for (auto [val, x, y] : coins) {
        coinBoard.push_back({x, y});
    }

    backTracking(0, 0);
    cout << (answer == 10000 ? -1 : answer) << '\n';
    return 0;
}
