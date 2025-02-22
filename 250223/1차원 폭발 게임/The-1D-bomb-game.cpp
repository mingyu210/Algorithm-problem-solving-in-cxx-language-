#include <iostream>
#include <vector>

using namespace std;

int n, m;
int numbers[100];
bool flag = false;
int end_of_numbers = 0;
vector<pair<int,int>> arr;

bool blea(int j){
    bool flag2 = true;
    for(int i=0; i<arr.size(); i++){
        if(j >= arr[i].first && j <= arr[i].second ){
            return false;
        }
        
    }
    return true;
}

void tnt(){
    int temp[100];
    int end_of_temp = 0;
    for(int j =0; j<end_of_numbers; j++){
        if(blea(j)){
            temp[end_of_temp++] = numbers[j];
        }
    }
    for(int i=0; i<end_of_temp; i++){
        numbers[i] = temp[i];
    }
    end_of_numbers = end_of_temp;

    
}

void lion(int q){
    if(q==1){
        if(m == 1){
            end_of_numbers = 0;
        }
        else{
            return;
        }
    }
    int first = 0;
    int last = 0;
    int num = 1;
    for(int i=1; i<q; i++){
        if(numbers[i-1] == numbers[i]){
            num++;
            last = i;
        }
        else{
            if(num >= m){
                arr.push_back({first,last});
                flag = true;
            }
            num = 1;
            first = i;
            last = i;
        }
    }
    if(num >= m){
        arr.push_back({first,last});
        flag = true;
    }
    tnt();
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    if(m == 1){
        cout << 0 << endl;
    }
    else{
        end_of_numbers = n;
        int num = 1;
        int first = 0;
        int last = 0;
        while(true){
            flag = false;
            lion(end_of_numbers);
            if(flag == false){
                break;
            }
            arr.clear();
        }

        cout << end_of_numbers<< endl;

        for(int i=0; i< end_of_numbers; i++){
            cout << numbers[i] << endl;
        }
    }
   


    return 0;
}
