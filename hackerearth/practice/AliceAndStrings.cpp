#include <iostream>

using namespace std;

int main(){
    string str1,str2;
    cin >> str1;
    cin >> str2;

    int flag = 0;
    for(long int i = 0;i < str1.size();i++){
        if(str2[i] - str1[i] < 0){
            flag = 1;
            break;
        }
    }

    if(flag == 0){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}