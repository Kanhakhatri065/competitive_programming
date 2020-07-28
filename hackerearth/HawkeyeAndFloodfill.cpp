#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int size;
    cin >> size;

    long long int board[size][size];

    int positionX, positionY;
    cin >> positionX >> positionY;

    long long int power;
    cin >> power;

    long long int distance;
    for(int i = 0;i < size;i++){
        for(int j = 0;j < size;j++){
            distance = max(abs(positionX - i), abs(positionY - j));
            if(distance >= power){
                board[i][j] = 0;
            } else {
                board[i][j] = power - distance;
                
            }
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}