#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

int n;
int grid[10][10];
bool visited[11];
int answer = INT_MIN;
vector<int> minAnswer;

void backTracking(int num){
    if(num == n){
        int miAnswer = INT_MAX;
        for(auto ac: minAnswer){
            miAnswer = min(miAnswer, ac);
        }
        answer = max(answer, miAnswer);
    }
    else{
        for(int i=0; i<n; i++){
            if(!visited[i]){
                visited[i] = true;
                minAnswer.push_back(grid[num][i]);
                backTracking(num+1);
                minAnswer.pop_back();
                visited[i] = false;
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

    backTracking(0);
    cout << answer;

    

    return 0;
}
