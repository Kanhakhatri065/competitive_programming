#include <bits/stdc++.h>

using namespace std;

int main() {
    int size;
    cin >> size;

    string str;
    cin >> str;

    int count = 0;
    int count_x = 0;
    for(int i = 0;i < size;i++) {
        if(str[i] == 'x') {
            count_x++;
        } else {
            if(count_x >= 3) {
                count += (count_x - 2);
            }
            count_x = 0;
        }
    }

    if(count_x >= 3) {
        count += (count_x - 2);
    }

    cout << count << endl;

    return 0;
}