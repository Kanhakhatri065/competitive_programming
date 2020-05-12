#include <iostream>

using namespace std;

int main() {
    int number;
    cin >> number;

    int arr[number];
    for(int i = 0;i < number;i++) {
        cin >> arr[i];
    }

    int flag = 0;
    for(int i = 0;i < number;i++) {
        if(arr[i] == 1) {
            flag = 1;
            break;
        }
    }

    if(flag == 0) {
        cout << "EASY" << endl;
    } else {
        cout << "HARD" << endl;
    }
    return 0;
}