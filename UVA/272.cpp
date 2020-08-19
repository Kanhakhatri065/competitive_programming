#include<bits/stdc++.h>

using namespace std;

int main(){
    string str;
    int i = 0,qut = 0;
    while(getline(cin, str)){
        for(int j = 0;str[j];j++){
            if(str[j] == '\"'){
                qut++;
                if(qut%2 == 0)cout << "\'" << "\'";
                else cout << "`" << "`";
            }
            else cout << str[j];
        }
        cout << endl;
    }
    return 0;
}

