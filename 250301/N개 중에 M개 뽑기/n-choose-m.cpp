#include <iostream>
#include <vector>

using namespace std;

int N, M;
bool visited[100];
vector<int> arr;


void backTracking(int u, int k){
    if(k == M){
        for(auto k : arr){
            cout << k << " ";
        }
        cout << endl;
    }
    else{
        for(int i=u; i<=N; i++){
            if(!visited[i]){
                arr.push_back(i);
                visited[i] = true;
                backTracking(i,k+1);
                visited[i] = false;
                arr.erase(arr.end() - 1);
            }
        }
    }

}

int main() {
    cin >> N >> M;
    backTracking(1,0);
    

    return 0;
}
