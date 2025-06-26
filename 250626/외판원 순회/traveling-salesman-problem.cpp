#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
int A[10][10];
bool visited[11];
vector<int> answer;
int realAnswer = INT_MAX;

void backTracking(int start , int num){
    if(num == n){
        if(A[start][1] != 0){
             int minAnswer = 0;
            answer.push_back(A[start][1]);
            for(auto ac: answer){
                minAnswer += ac;
            }
            if(minAnswer < realAnswer){
                realAnswer = minAnswer;
            }
            answer.pop_back();
        }
       
    }
    else{
        for(int i=1; i<=n; i++){
            if(start != i && !visited[i] && A[start][i]!=0){
                answer.push_back(A[start][i]);
                visited[i] = true;
                backTracking(i,num+1);
                answer.pop_back();
                visited[i] = false;
            }
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
    backTracking(1,1);
    cout << realAnswer;

    return 0;
}
