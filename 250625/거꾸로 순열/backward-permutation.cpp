#include <iostream>

using namespace std;

int n;
int arr[10];
bool visited[10];

void backTracking( int num){
    if(num == n){
        for(int i=0; i<n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    else{
        for(int i=n; i>0; i--){
            if(!visited[i]){
                arr[num] = i;
                visited[i] = true;
                backTracking(num+1);
                visited[i] = false;
            }
            
            
        }
    }
}

int main() {
    cin >> n;
    backTracking(0);
    

    return 0;
}
