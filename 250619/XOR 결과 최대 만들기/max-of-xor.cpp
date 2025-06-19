#include <iostream>

using namespace std;

int n, m;
int A[20];
int answer[20];
int answer2 = 0;





void backTracking(int idx, int num){
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
        for(int i=idx; i<n; i++){
        answer[num] = A[i];
        backTracking(i+1,num+1);
        
    }
    }
   
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    backTracking(0,0);
    cout << answer2;
    

    return 0;
}