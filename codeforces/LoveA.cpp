#include <iostream>

using namespace std;

int main() {
    string str;
    cin >> str;

    int count_a = 0;
    for(int i = 0;i < str.size();i++) {
        if(str[i] == 'a') {
            count_a++;
        }
    }

    if(count_a > (str.size() / 2)) {
        cout << str.size() << endl;
    } else {
        int total = str.size();
        while(count_a <= (total / 2)) {
            total--;
        }

        cout << total << endl;
    }

    return 0;
}