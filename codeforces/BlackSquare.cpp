#include <bits/stdc++.h>

typedef long long int ll;

using namespace std;

int main() {
    int calories[4];
    for(int i = 0;i < 4;i++) {
        cin >> calories[i];
    }

    string str;
    cin >> str;

    ll total_calories = 0;
    for(int i = 0;i < str.size();i++) {
        total_calories += calories[str[i] - 49];
    }

    cout << total_calories << endl;
    
    return 0;
}