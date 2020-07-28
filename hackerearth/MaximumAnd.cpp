#include <bits/stdc++.h>

using namespace std;

unsigned long long int maxAnd(unsigned long long int a, unsigned long long int b){
    if(a == b){
        return a;
    } else if(a - b == 1){
        return (a & b);
    } else {
        if(((b - 1) & b) > ((b - 2) & (b - 1))){
            return ((b - 1) & b);
        } else {
            return ((b - 2) & (b - 1));
        }
    }
}

int main(){
    int testcases;
    cin >> testcases;

    unsigned long long int a, b;
    unsigned long long int output;
    for(int i = 0;i < testcases;i++){
        cin >> a >> b;

        output = maxAnd(a,b);

        cout << output << endl;
    }
    return 0;
}