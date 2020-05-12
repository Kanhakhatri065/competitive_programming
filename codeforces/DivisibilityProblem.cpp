#include <iostream>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    long long int a, b;
    for(int i =  0;i < testcases;i++) {
        cin >> a >> b;
        long long int count = 0;
        int flag = a % b;
        if(flag != 0) {
            long long int quotitent = a / b;
            count = (quotitent + 1) * b - a;
        }
        cout << count << endl;
    }
    return 0;
}