#include <iostream>

using namespace std;

int main() {
    string check;
    cin >> check;

    string arr[5];
    for(int i = 0;i < 5;i++) {
        cin >> arr[i];
    }

    int flag = 0;
    for(int i = 0;i < 5;i++) {
        if(arr[i][0] == check[0] || arr[i][1] == check[1]) {
            flag = 1;
            break;
        }
    }

    if(flag == 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    return 0;
}