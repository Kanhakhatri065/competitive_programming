#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int left_experience, right_experience;
    cin >> left_experience >> right_experience;
    
    long long int left_cost, right_cost;
    cin >> left_cost >> right_cost;

    long long int efficiency;
    cin >> efficiency;

    int flag = 0;

    for(long long int i = left_cost; i <= right_cost;i++) {
        if(efficiency * i <= right_experience && efficiency * i >= left_experience) {
            flag = 1;
            break;
        }
    }

    if(flag == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
