#include <iostream>

using namespace std;

int main() {
    int size;
    cin >> size;

    int arr[size];
    for(int i = 0;i < size;i++) {
        cin >> arr[i];
    }

    int isAvailable = 0;
    int isUntreated = 0;

    for(int i = 0;i < size;i++) {
        if(arr[i] == -1) {
            if(isAvailable > 0) {
                isAvailable--;
            } else {
                isUntreated++;
            }
        } else {
            isAvailable += arr[i];
        }
    }

    cout << isUntreated << endl;

    return 0;
}