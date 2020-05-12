#include <iostream>

using namespace std;

int main() {
    int size;
    cin >> size;

    string str;
    cin >> str;

    int left = 0;
    int right = 0;
    for(int i = 0;i < size;i++) {
        if(str[i] == 'L') {
            left++;
        } else {
            right++;
        }
    }

    cout << (left + right + 1) << endl;
    return 0;
}