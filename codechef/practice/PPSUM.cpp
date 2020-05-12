#include <iostream>

using namespace std;

int sum(int n){
    if(n==1){
        return 1;
    }
    return n + sum(n-1);
}

int main(int argc, char const *argv[])
{
    int testcases;
    cin >>testcases;

    for(int i = 0;i < testcases;i++){
        int numOfTimes,number;
        cin >> numOfTimes >> number;

        int output = 0;

        while(numOfTimes != 0){
            output = sum(number);
            number = sum(number);
            numOfTimes--;
        }

        cout << output << endl;
    }

    return 0;
}
