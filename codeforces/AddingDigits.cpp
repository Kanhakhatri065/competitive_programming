#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main() {
    FAST
    int number, divisible, num_of_times;
    cin >> number >> divisible >> num_of_times;

    int flag = 0;
    for(int i = 0;i < 10;i++) {
        if((number * 10 + i) % divisible == 0) {
            number = number * 10 + i;
            flag = 1;
            break;
        }
    }

    if(flag == 1) {
        cout << number << string(num_of_times - 1, '0');
    } else {
        cout << "-1" << endl;
    }

    return 0;
}