#include <iostream>

using namespace std;

int main() {
    int lemons, apples, pears;
    cin >> lemons >> apples >> pears;

    int count = lemons;
    int flag = 0;
    while(flag == 0) {
        if(count <= lemons && ((2 * count) <= apples) && ((4 * count) <= pears)) {
            flag = 1;
            break;
        }

        if(count == 0) {
            break;
        }

        count--;
    }

    int total = count + (2 * count) + (4 * count);
    
    cout << total << endl;

    return 0;
}