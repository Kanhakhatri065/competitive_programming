#include <iostream>
#include <math.h>

using namespace std;

bool isPerfectSquare(unsigned long long int num){
    long double sr = sqrt(num);

    return (sr - floor(sr) == 0);
}

int main(){
    int size;
    cin >> size;

    long long int arr[size];
    for(int i = 0;i < size;i++){
        cin >> arr[i];
    }

    long long int total = 0;
    unsigned long long int tempSum = 0;
    for(int i = 0;i < size;i++){
        for(int j = size - 1;j >= i;j--){
            tempSum = 0;
            for(int k = i;k <= j;k++){
                tempSum += arr[k];
            }

            if(isPerfectSquare(tempSum)){
                total++;
            }
        }
    }

    cout << total << endl;

    return 0;
}