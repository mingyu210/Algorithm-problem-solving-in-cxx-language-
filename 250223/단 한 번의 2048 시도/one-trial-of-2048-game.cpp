#include <iostream>

using namespace std;

int grid[4][4];
char dir;

void up(){
    for(int i=0; i<4; i++){
        int temp[4];
        int end_of_temp = 0;
        for(int j = 0; j < 4; j++){
            if(grid[j][i] != 0){
                temp[end_of_temp++] = grid[j][i];
            }
        }
        int new_grid[4] = {0};
        int idx = 0;
        for (int j = 0; j < end_of_temp; j++) {
            if (j + 1 < end_of_temp && temp[j] == temp[j + 1]) {
                new_grid[idx++] = temp[j] * 2;
                j++; 
            } else {
                new_grid[idx++] = temp[j];
            }
        }
        
    }
}

void down(){
    for(int i=0; i<4; i++){
        int temp[4];
        int end_of_temp = 0;
        for(int j = 3; j>=0; j--){
            if(grid[j][i] != 0){
                temp[end_of_temp++] = grid[j][i];
            }
        }
        int new_grid[4] = {0};
        int idx = 3;
        for (int j = 0; j < end_of_temp; j++) {
            if (j + 1 < end_of_temp && temp[j] == temp[j + 1]) {
                new_grid[idx--] = temp[j] * 2;
                j++; 
            } else {
                new_grid[idx--] = temp[j];
            }
        }

        for (int j = 0; j < 4; j++) {
            grid[j][i] = new_grid[j];
        }
        
    }
}

void left(){
    for(int i=0; i<4; i++){
        int temp[4];
        int end_of_temp = 0;
        for(int j = 0; j < 4; j++){
            if(grid[i][j] != 0){
                temp[end_of_temp++] = grid[i][j];
            }
        }
        int new_grid[4] = {0};
        int idx = 0;
        for (int j = 0; j < end_of_temp; j++) {
            if (j + 1 < end_of_temp && temp[j] == temp[j + 1]) {
                new_grid[idx++] = temp[j] * 2;
                j++; 
            } else {
                new_grid[idx++] = temp[j];
            }
        }

        for (int j = 0; j < 4; j++) {
            grid[i][j] = new_grid[j];
        }
        
    }
}
void right(){
    for(int i=0; i<4; i++){
        int temp[4];
        int end_of_temp = 0;
        for(int j = 3; j>=0; j--){
            if(grid[i][j] != 0){
                temp[end_of_temp++] = grid[i][j];
            }
        }
        int new_grid[4] = {0};
        int idx = 3;
        for (int j = 0; j < end_of_temp; j++) {
            if (j + 1 < end_of_temp && temp[j] == temp[j + 1]) {
                new_grid[idx--] = temp[j] * 2;
                j++;
            } else {
                new_grid[idx--] = temp[j];
            }
        }

        for (int j = 0; j < 4; j++) {
            grid[i][j] = new_grid[j];
        }
        
    }
}


int main() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> dir;

    if(dir == 'R'){
        right();
    }
    else if(dir == 'L'){
        left();
    }
    else if(dir == 'U'){
        up();
    }
    else if(dir == 'D'){
        down();
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
