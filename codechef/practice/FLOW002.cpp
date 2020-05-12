#include <iostream>

using namespace std;

int main(){
    int testcases;
    cin >> testcases;

    for(int i = 0;i < testcases;i++){
        int a,b;
        cin >> a >> b;

        int output = a % b;
        cout << output << endl;
    }

    return 0;
}