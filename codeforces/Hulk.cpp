#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    string output = "";
    for(int i = 1;i <= n;i++) {
        if(i % 2 != 0) {
            output += "I hate";
        }

        if(i % 2 == 0) {
            output += "I love";
        }

        if(i < n) {
            output += " that ";
        }

        if(i == n) {
            output += " it";
        }
    }

    cout << output << endl;

    return 0;
}