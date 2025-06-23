#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int num[20];
int sum = 0;
int minSum = 0;
int answer=1e9;
bool visited[20];


void backTracking(int start ,int num2){
    if(num2 == n){
        if(answer > abs(sum - minSum)){
            answer = abs(sum - minSum);
        }
    }

    for(int i=start; i<2*n; i++){
        if(!visited[i]){
            minSum += num[i];
            sum -= num[i];
            visited[i] = true;
            backTracking(i+1,num2+1);
            minSum -= num[i];
            sum += num[i];
            visited[i] = false;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        cin >> num[i];
        sum += num[i];
    }
    backTracking(0,0);
    cout << answer;

    return 0;
}
