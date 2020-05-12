#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int total = 0;
    string str;
    while(n--) {
        cin >> str;
        if((str[0] == '+' && str[1] == '+') || (str[1] == '+' && str[2] == '+')) {
            total++;
        } else {
            total--;
        }
    }

    cout << total << endl;
    
    return 0;
}