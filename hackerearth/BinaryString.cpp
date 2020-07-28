#include <iostream>

using namespace std;

int main(){
    int testcases;
    cin >> testcases;

    int size;
    for(int i = 0;i < testcases;i++){
        cin >> size;

        string input;
        cin >> input;

        int count = 0;
        for(int j = 0;j < size;j++){
            if(input[j] == '0'){
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}