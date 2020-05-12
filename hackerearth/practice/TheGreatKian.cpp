#include <iostream>

using namespace std;

int main(){
    int size;
    cin >> size;

    int arr[size];
    for(int i = 0;i < size;i++){
        cin >> arr[i];
    }

    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;

    int counter1 = 0;
    int counter2 = 1;
    int counter3 = 2;

    for(int i = 0;i < size;i++){
        if(i == counter1){
            sum1 += arr[i];
            counter1 += 3;
        } else if(i == counter2){
            sum2 += arr[i];
            counter2 += 3;
        } else if(i == counter3){
            sum3 += arr[i];
            counter3 += 3;
        }
    }

    cout << sum1 << " " << sum2 << " " << sum3 << endl;

    return 0;
}