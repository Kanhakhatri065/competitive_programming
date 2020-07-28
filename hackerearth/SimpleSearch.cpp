#include <iostream>

using namespace std;

int main() {
    long long int size;
    cin >> size;

    long long int arr[size];
    for(long long int i = 0;i < size;i++) {
        cin >> arr[i];
    }

    long long int element;
    cin >> element;


    for(long long int i= 0;i < size;i++) {
        if(arr[i] == element) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}