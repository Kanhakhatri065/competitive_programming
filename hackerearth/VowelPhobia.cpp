#include <iostream>

using namespace std;

int main(){
    int testcases;
    cin >> testcases;

    for(int i = 0;i < testcases;i++){
        string input;
        cin >> input;

        unsigned long long int total = 0;
        for(long long int j = 0;j < input.size();j++){
            if(input[j] == 'a' || input[j] == 'e' || input[j] == 'i' || input[j] == 'o' || input[j] == 'u'){
                total++;
            }
        }

        cout << total << endl;
    }

    return 0;
}