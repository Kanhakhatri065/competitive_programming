#include <bits/stdc++.h>

using namespace std;

int main(){
    int testcases;
    cin >> testcases;

    long long int nth;
    for(int i = 0;i < testcases;i++){
        cin >> nth;

        nth = nth - 100;
        string str = "199999999999";

        if(nth / 12 == 0){
            if(nth % 12 != 0){
                str[0] = (((int)str[0] + 1) % 48) + 48;
                str[nth%12] = '8';
            }
        } else {
            str[0] = (((int)str[0] + 1 + (nth / 12))%48) + 48;
            if(nth % 12 != 0){
                str[nth%12] = 8;
            }
        }
        
        cout << str << endl;
    }
    return 0;
}