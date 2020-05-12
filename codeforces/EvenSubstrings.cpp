#include <iostream>

using namespace std;

int main() {
    int size;
    cin >> size;

    string str;
    cin >> str;

    int count = 0;
    for(int i = 0;i < size;i++) {
        int temp = str[i];
        temp -= 48;
        if(temp % 2 == 0) {
            count += (i + 1);
        }
    }

    cout << count << endl;
    
    return 0;
}