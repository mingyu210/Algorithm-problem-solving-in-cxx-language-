#include <iostream>

using namespace std;

int n, m;
int A[20];
int answer[20];
bool visited[20];
int answer2 = 0;





void backTracking(int num){
    if(num == m){
        int result = answer[0];
        for(int i=1; i<m; i++){
            result ^= answer[i];
        }
        if(answer2 < result){
            answer2 = result;
        }
    }
    else{
        for(int i=0; i<n; i++){
        if(!visited[i]){
            visited[i] = true;
            answer[num] = A[i];
        }
        backTracking(num+1);
        visited[i] = false;
    }
    }
   
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    backTracking(0);
    cout << answer2;
    

    return 0;
}