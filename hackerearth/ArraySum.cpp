#include <iostream>

using namespace std;

int main(){
    int size;
    cin >> size;

    unsigned long long int arr[size];
    for(int i = 0;i < size;i++){
        cin >> arr[i];
    }

    unsigned long long int sum = 0;
    for(int i = 0;i < size;i++){
        sum += arr[i];
    }

    cout << sum << endl;
    return 0;
}