#include <bits/stdc++.h>

using namespace std;

int main() {
    int size, divisible;
    cin >> size >> divisible;

    string output = "";
    if(size == 1 && divisible < 10) {
        output = to_string(divisible);
    } else if(size == 1 && divisible == 10) {
        output = "-1";
    } else {
        if(divisible != 10) {
            for(int i = 0;i < size;i++) {
                output += to_string(divisible);
            }
        } else {
            for(int i = 0;i < size - 1;i++) {
                output += to_string(1);
            }
            output += to_string(0);
        }
    }

    cout << output << endl;

    return 0;
}