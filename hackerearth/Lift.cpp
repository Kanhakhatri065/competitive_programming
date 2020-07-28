#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int testcases;
    cin >> testcases;

    int lift_a = 0;
    int lift_b = 7;

    for(int i = 0;i < testcases;i++){
        int floor;
        cin >> floor;

        if(abs(lift_a - floor) < abs(lift_b - floor)){
            cout << "A" << endl;
            lift_a = floor;
        } else if(abs(lift_a - floor) > abs(lift_b - floor)){
            cout << "B" << endl;
            lift_b = floor;
        } else {
            if((lift_a - lift_b) > 0){
                cout << "B" << endl;
                lift_b = floor;
            } else {
                cout << "A" << endl;
                lift_a = floor;
            }
        }
    }

    return 0;
}