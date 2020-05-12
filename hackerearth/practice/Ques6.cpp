#include <iostream>

using namespace std;

int main(){
    int testcases;
    cin >> testcases;

    int number = 0;
    for(int i = 0;i < testcases;i++){
        cin >> number;

        if(number == 1){
            cout << "*" << endl;
        } else {
            int total_size_of_line = number + (number - 1);
            int counter = 0;
            for(int j = 1;j <= number;j++){
                for(int k = 1;k <= ((total_size_of_line - (j + counter)) / 2);k++){
                    cout << " ";
                }

                for(int k = 1;k <= (j + counter);k++){
                    cout << "*";
                }

                for(int k = 1;k <= (total_size_of_line - (j + counter)) / 2;k++){
                    cout << " ";
                }
                cout << "\n";
                counter++;
            }
        }

    }

    return 0;
}