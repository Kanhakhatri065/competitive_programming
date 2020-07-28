#include <iostream>

using namespace std;

int main(){
    int testcases;
    cin >> testcases;

    long long int length, width;
    for(int i = 0;i < testcases;i++){
        cin >> length >> width;

        long long int output = 0;

        if(length >= width) {
            output = length / width;
        } else {
            output = width / length;
        }
        cout << output << endl;
    }
    return 0;
}