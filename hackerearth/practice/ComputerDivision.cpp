#include <iostream>

using namespace std;

int main(){
    int testcases;
    cin >> testcases;

    int number = 0;
    int answer = 0;
    for(int i = 0;i < testcases;i++){
        cin >> number;

        answer = 0;
        
        for(int j = 1;j <= number;j++){
            if(j >= (number/j)){
                answer++;
            }
        }

        cout << answer << endl;
    }
    return 0;
}