#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int num[20];
int sum = 0;
int minSum = 0;
int answer=0;

int main() {
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        cin >> num[i];
        sum += num[i];
    }

    sort(num, num+2*n);

    for(int i=0; i<n; i++){
        if(i == n-1){
            if((minSum + num[i]) - (sum - num[i]) > (minSum + num[2*n-i-1]) - (sum - num[2*n-i-1])){
                minSum += num[n-i-1];
                sum -= num[2*n-i-1];
            }
            else{
                minSum += num[i];
                sum -= num[i];
            }
        }
        else{
            minSum += num[i];
            sum -= num[i];
            minSum += num[2*n-i-1];
            sum -= num[2*n-i-1];
            i++;
        }
    }
    
    cout << abs(minSum - sum);

    return 0;
}
