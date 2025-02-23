#include <iostream>
#include <string>

using namespace std;

int Y, M, D;


bool Month(int a, int b, int c){
    if(a==2){
        if(c ==0){
            if(b>29){
                return false;
            }
            else{
                return true;
            }
        }
        else if(c==1){
            if(b>28){
                return false;
            }
            else{
                return true;
            }
        }
    }
   
    else if(a==4){
        if(b >30){
            return false;
        }
        else{
            return true;
        }
    }
   
    else if(a==6){
        if(b >30){
            return false;
        }
        else{
            return true;
        }
    }
   
    else if(a==9){
        if(b >30){
            return false;
        }
        else{
            return true;
        }
    }
    
    else if(a==11){
        if(b >30){
            return false;
        }
        else{
            return true;
        }
    }
    else{
        return true;
    }
   
}

string season(int m){
    if(m >=12 || m <=2){
        return "Winter";
    }
    else if(m >=3 && m <=5){
        return "Spring";
    }
    else if(m >=6 && m <=8){
        return "Summer";
    }
    else if(m >=9 && m <=11){
        return "Fall";
    }
}

int main() {
    cin >> Y >> M >> D;

    if(Y % 4 == 0 && Y % 100 != 0 || Y % 4 == 0 && Y % 100 == 0 && Y % 400 ==0 ){
        if(Month(M,D,0)){
            cout << season(M);
        }
        else{
            cout << -1;
        }

    }
    else{
        if(Month(M,D,1)){
            cout << season(M);
        }
        else{
            cout << -1;
        }
    }

    


    return 0;
}