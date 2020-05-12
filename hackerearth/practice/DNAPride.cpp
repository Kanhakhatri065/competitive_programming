#include <iostream>

using namespace std;

int main(){
    int testcases;
    cin >> testcases;

    long long int size;
    for(int i = 0;i < testcases;i++){
        cin >> size;

        string input;
        cin >> input;

        string output = "";
        for(int j = 0;j < size;j++){
            if ( input[j] == 'A' ) {
                output += 'T';
            } else if( input[j] == 'T' ) {
                output += 'A';
            } else if( input[j] == 'C' ) {
                output += 'G';
            } else if( input[j] == 'G' ) {
                output += 'C';
            } else {
                output = "Error RNA nucleobases found!" ;
                break;
            }
        }

        cout << output << endl;
    }
    
    return 0;
}