#include <iostream>

#define pi 22/7
using namespace std;

int main(){
    int days;
    cin >> days;

    int radius, amount;
    int toffees = 0;

    for(int i = 0;i < days;i++){
        cin >> radius >> amount;

        int distance = 2 * pi * radius;
        int max = 100 * amount;

        if(max >= distance){
            toffees++;
        }
    }

    cout << toffees << endl;

    return 0;
}