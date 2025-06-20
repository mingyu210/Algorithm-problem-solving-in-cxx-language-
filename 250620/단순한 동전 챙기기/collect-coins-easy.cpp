#include <iostream>
#include <vector>
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
        auto [x,y] = q.front();
        q.pop();

        for(int dir = 0; dir<4; dir++){
            int nx = x+dx[dir];
            int ny = y+dy[dir];

            if(nx >= 0 && nx < N && ny >= 0 && ny < N && dist[nx][ny] == -1){
                if(nx == second.first && ny == second.second){
                    return dist[x][y] + 1;
                }
                else if (grid[nx][ny] == '.'){ // 이동 가능한 조건
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    return 10000; // 도달 불가능한 경우
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
        minianswer += bfs(coinBoard[arr[2]], destination); // 마지막 코인 → 도착

        if(answer > minianswer){
            answer = minianswer;
        }
        return;
    }

    for(int i = start2; i < (int)coinBoard.size(); i++){
        arr.push_back(i);
        backTracking(i + 1, num + 1); // 여기 중요!!!
        arr.pop_back();
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
            if(grid[i][j] >= '1' && grid[i][j] <= '9'){
                coinBoard.push_back({i, j});
            }
            if(grid[i][j] == 'S'){
                start = {i,j};
            }
            if(grid[i][j] == 'E'){
                destination = {i,j};
            }
        }
    }


    sort(coinBoard.begin(), coinBoard.end(), [](const pair<int,int>& a, const pair<int,int>& b){
        return grid[a.first][a.second] < grid[b.first][b.second];
    });

    backTracking(0, 0);
    cout << (answer == 10000 ? -1 : answer) << '\n';
    return 0;
}
