#include <iostream>

using namespace std;

int main(){
    long long int testcases;
    cin >> testcases;

    for(long long int i = 0;i < testcases + 1;i++){
        string input;
        getline(cin,input);

        string output = "";
        for(int j = 0;j < input.size();j++){
            if(input[j] >= 65 && input[j] <= 90){
                int temp = input[j] -64;
                output += to_string(temp);
            } else if(input[j] >= 97 && input[j] <= 122) {
                int temp = input[j] - 96;
                output += to_string(temp);
            } else {
                output += "$";
            }
        }

        cout << output << endl;
    }

    return 0;
}