#include <iostream>

using namespace std;

int main() {
    int size;
    cin >> size;

    string arr[size];
    for(int i = 0;i <size;i++) {
        cin >> arr[i];
    }

    int flag = 0;
    for(int i = 0;i < size;i++) {
        if(arr[i][0] == 'O' && arr[i][1] == 'O') {
            flag = 1;
            arr[i][0] = arr[i][1] = '+';
            break;
        }

        if(arr[i][3] == 'O' && arr[i][4] == 'O') {
            flag = 1;
            arr[i][3] = arr[i][4] = '+';
            break;
        }
    }

    if(flag == 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for(int i = 0;i < size;i++) {
            cout << arr[i] << endl;
        }
    }

    return 0;
}