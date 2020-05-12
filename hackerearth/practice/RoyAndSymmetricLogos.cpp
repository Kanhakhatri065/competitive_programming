#include <iostream>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;
    for(int i = 0;i < testcases;i++) {
        int size;
        cin >> size;

        char arr[size][size];
        for(int j = 0;j < size;j++) {
            for(int k = 0;k < size;k++) {
                cin >> arr[j][k];
            }
        }

        bool horizontal_symmetrical = true;
        for(int j = 0;j < size;j++) {
            for(int k = 0;k < size / 2;k++) {
                if(arr[j][k] != arr[j][size - k - 1]) {
                    horizontal_symmetrical = false;
                    break;
                }
            }

            if(horizontal_symmetrical == false) {
                break;
            }
        }

        if(horizontal_symmetrical == false) {
            cout << "NO" << endl;
            continue;
        }

        bool vertical_symmetrical = true;
        for(int j = 0;j < size;j++) {
            for(int k = 0;k < size / 2;k++) {
                if(arr[k][j] != arr[size - k - 1][j]) {
                    vertical_symmetrical = false;
                    break;
                }
            }

            if(vertical_symmetrical == false) {
                break;
            }
        }

        if(vertical_symmetrical == false) {
            cout << "NO" << endl;
            continue;
        }

        if(horizontal_symmetrical == true && vertical_symmetrical == true) {
            cout << "YES" << endl;
        }
    }

    return 0;
}