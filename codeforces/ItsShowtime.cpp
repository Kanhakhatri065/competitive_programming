#include <bits/stdc++.h>

using namespace std;

unsigned long long int double_factorial(long long int number) {
    if(number == 0 || number == 1) {
        return 1;
    }
    else {
        return number * double_factorial(number - 2);
    }
}

int main() {
    string str;
    cin >> str;

    string last_three = "";
    for(int i = str.size() - 3;i < str.size();i++) {
        last_three += str[i];
    }

    stringstream ss(last_three);
    int moda;
    ss >> moda;

    string num = "";
    for(int i = 0;i < str.size() - 3;i++) {
        num += str[i];
    }

    stringstream ss1(num);
    int n;
    ss1 >> n;
    cout << (double_factorial(n) % moda) << endl;

    return 0;
}