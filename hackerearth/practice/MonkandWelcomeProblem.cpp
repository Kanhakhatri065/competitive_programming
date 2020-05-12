#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n];
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }

    int b[n];
    for(int i = 0;i < n;i++){
        cin >> b[i];
    }

    for(int i = 0;i < n;i++){
        cout << (a[i] + b[i]) << " ";
    }
    return 0;
}