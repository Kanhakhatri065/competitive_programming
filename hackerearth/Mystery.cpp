#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a;
    
    int count = 0;
    while(cin >> a){
        count = 0;
        while(a){
            a = a &(a - 1);
            count++;            
        }
        cout << count << endl;
    }

    return 0;
}