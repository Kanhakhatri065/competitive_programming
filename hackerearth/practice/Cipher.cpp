#include <bits/stdc++.h>

using namespace std;

int main(){
    string str;
    cin >> str;

    int key;
    cin >> key;

    for(int i = 0;i < str.length();i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = ((str[i] - 65 + key) % 26) + 65;
        } else if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] = ((str[i] - 97 + key)%26) + 97;
        } else if(str[i] >= '0' && str[i] <= '9'){
            str[i] = ((str[i] - 48 + key)%10) + 48;
        }
    }
    
    cout << str << endl;
    
    return 0;
}