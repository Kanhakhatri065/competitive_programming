#include <iostream>

using namespace std;

int main(){
    int size;
    cin >> size;

    int first_even_series = 20;
    int first_odd_series = 30;

    int arr[size];
    arr[0] = first_even_series;
    arr[1] = first_odd_series;

    for(int i = 2;i < size;i++){
        if(i % 2 == 0){
            arr[i] = 2 * first_even_series;
            first_even_series = first_even_series * 2;
        } else {
            arr[i] = 3 * first_odd_series;
            first_odd_series = first_odd_series * 3;
        }
    }

    if(size % 2 == 0){
        cout << (2 * arr[size - 1]) << endl;
    } else {
        cout << (2 * arr[size - 2]) << endl;
    }
    return 0;
}