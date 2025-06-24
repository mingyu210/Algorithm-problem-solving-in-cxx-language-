#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> arr;
bool visited[9];

void backTracking(int num){
    if(num == n){
        for(auto n : arr){
            cout << n << " ";
        }
        cout << endl;
    }
    else{
        for(int i=1; i<=n; i++){
            if(!visited[i]){
                arr.push_back(i);
                visited[i] = true;
                backTracking(num+1);
                arr.pop_back();
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
