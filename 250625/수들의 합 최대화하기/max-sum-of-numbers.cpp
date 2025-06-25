#include <iostream>
#include <vector>
using namespace std;

int n;
int grid[11][11];
vector<int> minAnswer;
int answer;
bool visited[11];


void backTracking(int start, int num){
    if(num == n){
        int aw = 0;
        for(int uan : minAnswer){
            aw += uan;
        }
        if(aw > answer){
            answer = aw;
        }
    }
    else{
            for(int j=0; j<n; j++){
                if(!visited[j]){
                    minAnswer.push_back(grid[start][j]);
                    visited[j] = true;
                    backTracking(start+1, num+1);
                    visited[j] = false;
                    minAnswer.pop_back();
                }
            }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    backTracking(0,0);
    cout << answer;

    return 0;
}
