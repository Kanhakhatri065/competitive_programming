#include <iostream> 

using namespace std;

int main() {
    int size;
    cin >> size;

    long long int element;
    cin >> element;

    long long int arr[size];
    for(int i = 0;i < size;i++) {
        cin >> arr[i];
    }

    long long int position = -1;
    for(int i = 0;i < size;i++) {
        if(arr[i] == element) {
            position = i + 1;
        }
    }

    cout << position << endl;

    return 0;
}